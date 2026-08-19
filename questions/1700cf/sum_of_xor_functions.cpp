#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<long long> a(n);
	for (int i = 0;i<n;++i){
		cin >> a[i];
	}
	long long ans = 0;
	long long mod = 998244353;
	for (int b = 0;b<31;++b){
		vector<long long> suml = {1,0};
		vector<long long> numl = {1,0};
		long long pref = 0;
		long long tempans = 0;
		for (int r = 1;r<n+1;++r){
			long long bv = (a[r-1] >> b) & 1;
			pref ^= bv;
			
			tempans += (r+1)*numl[1^pref] - suml[1^pref];
			tempans %= mod;
			
			numl[pref]++;
			suml[pref] += r+1;
			suml[pref] %= mod;
			
		}
		long long pow2 = (1LL << b) % mod;
		ans += pow2 * tempans;
		ans %= mod;
	}
	cout << ans << '\n';
}
