#include<iostream>
#include<vector>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int convert_num(string str){

    int num = 0;
    int unit =1; // 1000s,100s, 10s, 1s
    for(int i=str.length()-1; i>=0; i--){
        int val = (str[i]-'0')*unit;
        num+=val;
    }
    return num;
}

bool cmp_numeric(pair<string, string> a, pair<string, string> b){
    return convert_num(a.second) < convert_num(b.second);

}

bool cmp_lexical(pair<string,string> a, pair<string, string> b){
    return a.second < b.second;
}
string getColumnarToken(string str, int key){

    char *token = strtok((char*)str.c_str()," "); // convert string to character string
    while(key>1){
        token = strtok(NULL," ");
        key--;
    }
    return (string)token;
}
int main(){
    // cout<<getColumnarToken("Hello in ayush world",3);
    
    int n;
    cin>>n;
    cin.get(); // to go to new line for input and avoid spaces in this line

    vector<string> v_s(n);
    string temp;

    for(int i=0; i<n; i++){
        getline(cin,temp);
        v_s[i]=(temp);
    }

    int key;
    string reversal, is_numeric;
    cin>> key >> reversal >> is_numeric;
    
    vector<pair<string,string>> key_str_vect;
    string key_str;
    for(int i=0; i<n; i++){
        key_str = getColumnarToken(v_s[i],key);
        key_str_vect.push_back({key_str,v_s[i]});
    }

    if (is_numeric == "true"){
        sort(key_str_vect.begin(), key_str_vect.end(), cmp_numeric);
    }else{
        sort(key_str_vect.begin(), key_str_vect.end(), cmp_lexical);
    }

    if(reversal=="true"){
        reverse(key_str_vect.begin(), key_str_vect.end());
    }

    for(int i=0;i<n; i++){
        cout<<key_str_vect[i].second<<endl;
    }
    return 0;
}