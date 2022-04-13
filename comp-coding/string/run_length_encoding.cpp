#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
  int i=0;
  string ans="";
  for(;i<str.size()-1;i++){
      int cnt=1;
      while(i<str.size()-1 && str[i]==str[i+1]){
          cnt++;
          i++;
      }
    //   if(cnt>1){
    //       ans=ans+str[i]+to_string(cnt);
    //   }else{
    //       ans=ans+str[i];
    //   }
    ans=ans+str[i]+to_string(cnt);
  }
  if(str.size()>1 && str[str.size()-1]!=str[str.size()-2]){
      ans+= str[str.size()-1];
  }
  if(str.size()==1){
      ans+=str[0];
  }
  if(ans.size()>=str.size()){
      return str;
  }else{
      return ans;
  }
  
   
}
int main(){
    cout<<compressString("bbbaaaadexxxxxx")<<endl;
    cout<<compressString("abc")<<endl;
    return 0;
}