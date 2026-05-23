#include <bits/stdc++.h>

using namespace std;

// 1466 E. Apollo vs Pan - Codeforces

int main(){
	long long mod = 1e9 + 7;
	int t;
	cin >> t;
	vector<long long> modpowers(60);
	long long val = 1;
	for (int i = 0;i<60;++i){
		modpowers[i] = val;
		val*=2; 
		val %= mod;
	}
	while (t--){
		int n;
		long long summation = 0;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
			summation += a[i];
		}
		vector<long long> cnt(60,0);
		for (int i = 0;i<n;++i){
			long long value = a[i];
			for (int j = 0;j<60;++j){
				cnt[j] += value&1;
				value >>= 1;
				if (value == 0){
					break;
				}
			}
		}
		long long xjbit;
		long long ans3 = 0;
		for (int j = 0;j<n;++j){
			long long ans2 = 0;	
			long long ans = 0;	
			xjbit = a[j];
			long long power = 0;
			for (int k=0;k<60;++k){
				ans += (xjbit&1)?(cnt[power]*modpowers[power]):0;
				ans2 += ((xjbit&1)?(n*modpowers[power]):(cnt[power]*modpowers[power]));
				xjbit >>= 1;
				power++;
				ans %= mod;
				ans2 %= mod;				
			}
			ans3 += (ans*ans2)%mod;	
			ans3 %= mod;	
		}
		cout << ans3 << endl;
		
	}
}
