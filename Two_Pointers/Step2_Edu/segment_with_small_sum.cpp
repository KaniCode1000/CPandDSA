#include <iostream>
using namespace std;

int main(){
	long long n,s;
	cin >> n >> s;
	long long arr[n];
	for (long long i = 0;i<n;i++){
		cin >> arr[i];
	}
	long long summ = 0;
	long long low = 0,res = 0;
	for (long long r = 0;r<n;r++){
		summ += arr[r];
		while (summ > s){
			summ -= arr[low];
			low++;
		}
		res = res > (r-low+1)?res:(r-low+1);
	}
	cout << res << endl;
	
}
