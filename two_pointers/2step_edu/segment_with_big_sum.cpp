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
	bool done = false;
	long long low = 0,res = n;
	for (long long r = 0;r<n;r++){
		summ += arr[r];
		while (summ - arr[low] >= s){
			summ -= arr[low];
			low++;
		}
		if (summ >= s){
			done = true;
			res = res < (r-low+1)?res:(r-low+1);
		}
	}
	cout << (done?res: (long long) (-1)) << endl;
	
}

