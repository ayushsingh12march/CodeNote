// refer :- https://comcast.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/23917400#overview
#include<iostream>
#include<cstring>
using namespace std;

char* my_tokenizer(char *s, char delimiter){
    static char* input=NULL;

    if(s != NULL){
        input = s;
    }
    //to handle segmentation fault
    if(input == NULL){

        return NULL;
    }
    // cout<<"input is "<<input<<endl;
    char *token = new char[strlen(input)+1];
    int i = 0;
    for(; input[i]!='\0'; i++){
        if(input[i]== delimiter){
            token[i]='\0';
            input =input + i +1;
            return token;
        }else{
            token[i]=input[i];
        }

    }
    
    token[i] = '\0'; // for last word that does not have delimiter
    input = NULL;
    // cout<<"done"<<endl;
    return token;



}
void tokenize(char *s){
    char *token = my_tokenizer(s,' ');
    while(token!=NULL){
        cout<<token<<endl;
        token = my_tokenizer(NULL,' ');
    }
}
int main(){
    char s[1000];
    cin.getline(s,1000);
    tokenize(s);
    return 0;
}