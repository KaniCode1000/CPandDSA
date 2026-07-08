#include <bits/stdc++.h>
using namespace std;

//1350 B. Orac and Models - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<long long> s(n+1);
		for (int i = 0;i<n;++i) cin >> s[i+1];
		vector<long long> dp(n+1,1);
		for (int i = 1; i <= n;++i){
			for (int j = 2;j<= n/i;++j){
				if (s[i*j] > s[i]){
					dp[i*j] = max(dp[i*j],1+dp[i]);
				}
			}
		}
		long long ans = 0;
		for (long long i: dp){
			ans = max(i,ans);
		}
		cout << ans << '\n';
	}
}
