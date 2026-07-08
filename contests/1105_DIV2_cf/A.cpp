#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		long long n,k; cin >> n >> k;
		long long value = 1;
		long long ans = 0;
		if (n < k){
			cout << n << '\n';
			continue;
		}
		while (n >= k*value){
			n-= k*value;
			ans++;
			value <<=1;	
		}	
		cout << k*ans + n/value << '\n'; 
	}
}
