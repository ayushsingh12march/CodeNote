#include<bits/stdc++.h>
using namespace std;

string convertToString(int num){
    if(num<9){
        return "0"+ to_string(num);
    }
    return to_string(num);
}
string convert_to_digital_time(int minutes){
    //complete this function
    int hour = minutes/60;
    if(hour == 24){
        hour=0;
    }
    minutes = minutes%60;
    return convertToString(hour)+":"+convertToString(minutes);
}

int main(){
    cout<<convert_to_digital_time(1180)<<endl;
    cout<<convert_to_digital_time(125)<<endl;
    cout<<convert_to_digital_time(155)<<endl;
    return 0;
}