#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	vector<long long> a(n);
	for (long long &x: a) cin >> x;
	auto bin_search= [&](int value){
	int low = 0,high = n-1;
	while (low <= high){
		int m = low + (high-low)/2;
		if (a[m] == value){
			return m;
		}
		else if(a[m] < value){
			low = m+1;
		}
		else{
			high = m-1;
		}
	}
	return -1;
	
	};
	while (k--){
		long long value; cin >> value;
		if (bin_search(value) == -1 ){
			cout << "NO" << '\n';
		}	
		else{
			cout << "YES" << '\n';
		}
	}	
}
