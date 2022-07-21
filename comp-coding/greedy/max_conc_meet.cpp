#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> max_concurrent_metings(vector<vector<int>> arr){
    vector<int> start_time,end_time;
    for(int i=0;i<arr.size();i++){
        start_time.push_back(arr[i][0]);
        end_time.push_back(arr[i][1]);
    }
    sort(start_time.begin(),start_time.end());
    sort(end_time.begin(),end_time.end());
    // find maximum concurrent and what is maximum concurrent start time
    int max_concurrent=-1,max_concurrent_start=-1,concurrent=0,max_concurrent_end=-1;
    int i=0,j=0;
    while(i<arr.size() && j<arr.size()){
        if(start_time[i]<=end_time[j]){
            concurrent++; 
            if(max_concurrent<concurrent){
                max_concurrent = concurrent;
                max_concurrent_start=start_time[i];
            }
            i++;
        }else{
            concurrent--;
            j++;
        }
        
    }
    // find maximum concurrent end time
    i=0,j=0;
    concurrent=0;
    while(i<arr.size() && j<arr.size()){
        if(start_time[i]<=end_time[j]){
            concurrent++; 
            
            i++;
        }else{
            if(max_concurrent==concurrent){
                max_concurrent_end=end_time[j];
                break;
            }
            concurrent--;
            j++;
        }
        
    }
    // for(vector<int> i : arr){
    //     if(i[0]==max_concurrent_start){
    //         return {i};
    //     }
    // }
    return {{max_concurrent_start,max_concurrent_end}};
}
int main(){

    // vector<vector<int>> arr = {{100, 300}, {145, 215}, {200, 230}, {215, 300}, {215, 400}, {500, 600}, {600, 700}} ;
    // vector<vector<int>> arr = {{100, 200}, {50, 300}, {300, 400}}  ;
    vector<vector<int>> arr = {{2, 10}, {3, 15}, {4, 9}, {8, 14}, {7, 13}, {5, 10}, {11, 15}} ;
    vector<vector<int>> ans = max_concurrent_metings(arr);
    for(vector<int> i : ans){
        cout<<i[0]<<", "<<i[1]<<endl;
    }
}