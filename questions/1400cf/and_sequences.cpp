#include <bits/stdc++.h>
using namespace std;

//1513 B. And Sequences - Codeforces

int main(){
	int t; cin >> t;
	long long mod = 1e9 + 7;
	while (t--){
		int n; cin >> n;
		vector<long long> a(n);
		long long fac = 1;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			if (i < n-2)
				fac = (fac * (i+1))%mod;
		}
		long long tand = a[0];
		for (long long x: a){
			tand &= x;
		}
		long long count = 0;
		for (long long x: a){
			if (tand == x)
				count++;
		}	
		fac *= count;
		fac %= mod;
		fac *= (count-1);
		fac %= mod;
		cout << fac << '\n';
	}
}
