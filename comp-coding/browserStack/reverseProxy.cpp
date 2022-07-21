#include<bits/stdc++.h>
using namespace std;

vector<string> split(string str, const char* delimiter){
    char *token = strtok((char*)str.c_str(),delimiter);
    vector<string> result;
    while(token != NULL){
        result.push_back(token);
        token = strtok(NULL,delimiter);
    }
    return result;

}

class ReverseProxy{

    vector<string> machine_ip;
    unordered_map<string,vector<string>> domain_to_machine;
    unordered_map<string,vector<string>> machine_to_domain;
    unordered_map<string,int> domain_to_rrid;

public:
    ReverseProxy(vector<string> machine_ip){
        this->machine_ip = machine_ip;
        
    }
    void host_ip_mapper(string domain, vector<string> ips){
        if(domain_to_machine.count(domain)==0){
            domain_to_machine[domain] = ips;
            domain_to_rrid[domain] = 0;
        }else{
            for(string ip: ips){
                domain_to_machine[domain].push_back(ip);
            }
        }
        
        for(auto ip : ips){
            if(machine_to_domain.count(ip)!=0){
                machine_to_domain[ip].push_back(domain);
            }else{
                vector<string> temp;
                temp.push_back(domain);
                machine_to_domain[ip] = temp;
            }
        }
    }

    void request(string req){
        vector<string> url = split(req,"/");
        // cout<<url[0]<<", "<<url[1]<<endl;
        int index = url[1].find("machine");
        if(index == -1){
            //rr request
            // cout<<"in if"<<endl;
            if(domain_to_machine[url[0]].size()==0){
                cout<<"Cannot process the host"<<url[0];
                return;
            }
            int index = domain_to_rrid[url[0]]%domain_to_machine[url[0]].size();
            cout<<domain_to_machine[url[0]][index]<<endl;
            domain_to_rrid[url[0]] = (domain_to_rrid[url[0]]+1)%domain_to_machine[url[0]].size();
            cout<<req<<endl;

        }else{
            // cout<<"in else"<<endl;
            index = url[1].find("machine_up");
            string ip = split(req,"=")[1];
            if(index!=-1){
                //machine_up
                cout<<"machine_up"<<endl;
                bool found_domain = 0;
                for(string domain : machine_to_domain[ip]){
                    if(domain == url[0]){
                        found_domain = 1;
                        break;
                    }
                }
                if(!found_domain)
                    host_ip_mapper(url[0],{ip});

            }else{
                //machine_down
                //find_ip_domains
                // cout<<"machine_down"<<endl;
                for(string domain : machine_to_domain[ip]){
                    int i=0;
                    
                    // cout<<"domain is "<<domain<<", ip "<<ip<<endl;
                    for(string machine : domain_to_machine[domain]){
                        // cout<<"FINDING - "<<machine<<endl;
                        if(machine == ip){
                            // cout<<"FOUND"<<endl;
                            auto iterator = domain_to_machine[domain].begin()+i;
                            if(i<domain_to_rrid[domain]){
                                //iterator update required// just remove
                                domain_to_rrid[domain]--;
                                /* if(domain_to_rrid[domain]>0)
                                //     domain_to_rrid[domain]--;
                                // else{
                                //     int old_size =  domain_to_machine[domain].size();
                                //     domain_to_rrid[domain] = old_size > 1 ? old_size-2 : 0;
                                 }*/
                                    
                            }
                            domain_to_machine[domain].erase(iterator);
                            cout<<"removed";
                             break;
                        }

                        i++;
                       
                    }
                }
                machine_to_domain.erase(ip);
            }
        }
    }

    void display(){
        cout<<"-------------------------------------------------"<<endl;
        for(auto i : machine_ip){
            cout<<i<<endl;
        }
        cout<<"-------------------------------------------------"<<endl;
        for(auto i : machine_to_domain){
            cout<<i.first<<" - ";
            for(string j : i.second){
                cout<<j<<", ";
            }cout<<endl;
        }
        cout<<"-------------------------------------------------"<<endl;
        for(auto i : domain_to_machine){
            cout<<i.first<<" - ";
            for(string j : i.second){
                cout<<j<<", ";
            }cout<<endl;
        }

    }

};

int main(){
    vector<string> machine_ip;
    machine_ip.push_back("localhost1");
    machine_ip.push_back("localhost2");
    machine_ip.push_back("localhost3");
    machine_ip.push_back("localhost4");
    machine_ip.push_back("localhost5");
    //mapping
    string domain_name = "www.h1.com";
    vector<string> ips;
    ips.push_back("localhost3");
    ips.push_back("localhost1");
    
    string domain_name2 = "www.h2.com";
    vector<string> ips2;
    ips2.push_back("localhost2");
    ips2.push_back("localhost4");
    ips2.push_back("localhost5");

    ReverseProxy rp(machine_ip);
    // rp.display();
    //round_robin
    rp.host_ip_mapper(domain_name,ips);
    rp.request("www.h1.com/req1");
    

    rp.host_ip_mapper(domain_name2,ips2);
    rp.request("www.h2.com/req1");

    rp.request("www.h1.com/req1");
    rp.request("www.h2.com/req1");

    rp.request("www.h1.com/req1");
    rp.request("www.h2.com/req1");

    rp.request("www.h1.com/req1"); // 1 -> (3,1)
    rp.request("www.h2.com/req1"); // 2 -> (2,4,5)
    rp.display();
    cout<<"-----------"<<endl;
    rp.request("www.h1.com/machine_down?ip=localhost3");  // 1 -> (1)
    rp.request("www.h2.com//machine_up?ip=localhost4"); // 4 -> (2,4,5,3)
    rp.display();
    // rp.request("www.h1.com/req1");
    // rp.request("www.h2.com/req1");

    // rp.request("www.h1.com/req1");
    // rp.request("www.h2.com/req1");

    // rp.request("www.h1.com/req1");
    // rp.request("www.h2.com/req1");

    // rp.request("www.h1.com/req1");
    // rp.request("www.h2.com/req1");
    //unmap
    return 0;
}

