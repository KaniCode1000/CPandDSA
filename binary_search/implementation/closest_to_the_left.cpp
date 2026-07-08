#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	vector<long long> a(n);
	for (long long &x: a) cin >> x;
	auto lbound= [&](int value){
	int low = 0,high = n-1,found = -1;
	while (low <= high){
		int m = low + (high-low)/2;
		if (a[m] <= value){
			low = m+1;
			found = m;
		}
		else{
			high = m-1;
		}
	}
	return found+1;;
	
	};
	while (k--){
		long long value; cin >> value;
		cout << lbound(value) << '\n';
	}	
}
