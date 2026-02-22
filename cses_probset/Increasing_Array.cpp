#include <iostream>
using namespace std;

//Counts number of operations away from making increasing array
long ops_incarray(int n,long arr[]){
	long ans = 0;
	for (int i = 1;i<n;i++){
		if (arr[i] < arr[i-1]){
			ans += (arr[i-1]-arr[i]);
			arr[i] = arr[i-1];
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	long arr[n];
	for (int i = 0;i<n;i++){
		cin >> arr[i];
	}
	long val = ops_incarray(n,arr);
	cout << val << endl;
}
