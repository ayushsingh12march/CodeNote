#include<bits/stdc++.h>
using namespace std;

void all_subsets(vector<int> a, int i,vector<int> op){
    if(i==a.size()){
        for(int k : op){
            cout<<k<<", ";
        }cout<<endl;
        return;
    }
    all_subsets(a,i+1,op);
    op.push_back(a[i]);
    all_subsets(a,i+1,op);
    
}
int main(){
    vector<int> arr = {1,2,3};
    vector<int> op;
    all_subsets(arr,0,op);
}