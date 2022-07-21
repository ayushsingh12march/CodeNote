#include<bits/stdc++.h>
using namespace std;

long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    if(total==0){
        return 0;
    }
    long long count=0;
    
    if(total>=cost1){
        count += waysToBuyPensPencils(total-cost1,cost1,cost2)+1;
    }
    if(total>=cost2){
        count += waysToBuyPensPencils(total-cost2,cost1,cost2)+1;
    }
    cout<<total<<" -  "<<count<<endl;
    return count;
}

int main(){
    cout<<waysToBuyPensPencils(20,10,5);
    return 0;
}