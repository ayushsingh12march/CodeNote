#include <iostream>
using namespace std;
bool isSpiral(long arr[], long n){
	long start = 0;
	long end = n-1;
	while(start<end){
		if(arr[start]>arr[end]){
			return 0;
		}
		start++;
		if(arr[end]>arr[start]){
			return 0;
		}
		end--;
	}
	return 1;
}
int main() {
	long n;
	cin >> n;    //Reading input from STDIN
	long arr[n];
	for(long i=0;i<n;i++){
		cin>>arr[i];
	}
	if(isSpiral(arr,n)){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	

	return 0;

}