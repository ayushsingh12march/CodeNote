#include<iostream>
#include<cstring>
using namespace std;

void replace_space(char *str){
    int space_count=0;
    for(int i=0; str[i]!='\0' ; i++){
       if(str[i]==' '){
           space_count++;
       }
    }

    int last_index = strlen(str)  + (space_count*2);

    int j = last_index-1;
    for(int i = strlen(str)-1; i>=0;i--){
        // cout<<str[i]<<endl;
        // break;
        if(str[i]!=' '){
            str[j--]=str[i];
        }else{
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
    }

}

int main(){
    char s[2000];
    cin.getline(s,1000);
    replace_space(s);
    cout<<s<<endl;
}
