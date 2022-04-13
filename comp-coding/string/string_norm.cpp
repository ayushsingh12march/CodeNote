#include<bits/stdc++.h>
using namespace std;



string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    if(copy[0]>='a' && copy[0]<='z'){
        copy[0]-=32;
    }
    for(int i=1;i<copy.size();i++){
        if(copy[i-1]!=' '){
            if(copy[i]>='A' && copy[i]<='Z'){
                copy[i]+=32;
            }
        }else{
            if(copy[i]>='a' && copy[i]<='z'){
                copy[i]-=32;
            }
        }
        
    }
    return copy;
     
}

int main(){
    string sent = "This is SO MUCH FUN";
    cout<<normalize(sent);
    return 0;
}