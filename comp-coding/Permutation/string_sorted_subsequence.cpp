#include<bits/stdc++.h>
#include<string.h>
using namespace std;

bool cmp(string a, string b){
    if(a.size()<b.size()){
        return true;
    }else if(a.size()>b.size()){
        return false;
    }else{
        return a<b;
    }
}
void sorted_subsequence(string s, vector<string> &subseq, string output){
    if(s.size()==0){
        // output+=s;
        subseq.push_back(output);
        return;
    }
    char first_letter = s[0];

    s = s.substr(1);
    sorted_subsequence(s,subseq,output+first_letter);
    sorted_subsequence(s,subseq,output);
}
int main(){
    string s;
    cin>>s;
    vector<string> subseq;
    string output="";
    sorted_subsequence(s,subseq,output);
    sort(subseq.begin(), subseq.end(),cmp);
    for(string i : subseq){
        cout<<i<<", ";
    }cout<<endl;
}