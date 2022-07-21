#include<bits/stdc++.h>
using namespace std;

void all_permute(vector<int> a,int i){
    if(i==a.size()){
        for(int k : a){
            cout<<k<<", ";
        }cout<<endl;
        return ;
    }
    for(int j=i;j<a.size();j++){
        swap(a[i],a[j]);
        all_permute(a,i+1);
        
        swap(a[i],a[j]); //backtrack
    }
    
}
int main(){
    vector<int> arr = {1,2,3};
    // vector<int> op;
    all_permute(arr,0);
}