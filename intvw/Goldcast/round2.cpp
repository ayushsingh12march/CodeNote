/*
    Question :- Create a data structure and functions such that you can add string , remove string, remove string from random position in avg O(1) time complexity 

*/

#include <bits/stdc++.h>
using namespace std;

class AllFor1 {
  
  vector<string> v;
  unordered_map<string, int> mp;
  public:
  
    void add(string item){
      if(mp.count(item)!=0){
        cout<<"Item is already present"<<endl;
        return;
      }
      v.push_back(item);
      mp[item] = v.size()-1;
    }
    
    void remove(string item){
      if(mp.count(item)==0){
        cout<<"item is not present"<<endl;
        return;
      }
      int last_index = v.size()-1;
      
      int index = mp[item];
      string last_ele = v[last_index];
      //swap and update map index
      mp[last_ele] = index;
      swap(v[index],v[last_index]);
      
      
      // remove from vector and map
      v.erase(v.end()-1);
      mp.erase(item);
      
    }
    
    string removeRandom(){
      
      int last_index = v.size()-1;
      if(last_index<0){
        cout<<"No item available to be removed"<<endl;
        return "-1";
      }
      int rand_index = rand(0,last_index);
      string remove_str = v[rand_index];
      remove(remove_str);
      return remove_str;
      
    }
    
    int rand(int start, int end){
      return start + ( std::rand() % ( end - start + 1 ) );
    }
    
    void print(){
      for(string i : v){
        cout<<i<<" ";
      }cout<<endl;
    }
  
};
int main(){
  
  AllFor1 obj;
  obj.add("foo");
  obj.add("car");
  obj.add("zoo");
  obj.add("bar");
  obj.print();
  obj.remove("foo");
  obj.print();
  string rand_remove = obj.removeRandom();
  cout<<"Removed : "<< rand_remove <<endl;
  obj.print();
  rand_remove = obj.removeRandom();
  cout<<"Removed : "<< rand_remove <<endl;
  obj.print();
  rand_remove = obj.removeRandom();
  cout<<"Removed : "<< rand_remove <<endl;
  obj.print();
  rand_remove = obj.removeRandom();
  cout<<"Removed : "<< rand_remove <<endl;
  obj.print();
  return 0;
}
// add foo
// add bar
// add zoo
// add car

// remove bar
// removeRandom() -> car

// Your last C/C++ code is saved below:

