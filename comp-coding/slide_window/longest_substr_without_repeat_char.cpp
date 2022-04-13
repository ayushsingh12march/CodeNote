#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        
        int global_longest=0;
        for(int i=0; i<s.length(); ){
            // cout<<i<<endl;
            int local_length = 0;
            unordered_map<char, int> mp;
            int j=i;
            bool going_back = false;
            for(;j<s.length();j++){
                // cout<<s[j]<<" - "<<mp.count(s[j])<<endl;
                if(mp.count(s[j])==0){
                    mp[s[j]]=j;
                    local_length++;
                    
                }else{
                    i = mp[s[j]]+1;
                    // cout<<"i -> "<<i<<endl;
                    going_back = 1;
                    break;
                }
            }
            // break;
            if(!going_back)
            {
                i=j;
            }
            global_longest = max(global_longest,local_length);

        }
        return global_longest;
}

int main(){
    cout<<lengthOfLongestSubstring("abcabcbb");
    return 0;
}