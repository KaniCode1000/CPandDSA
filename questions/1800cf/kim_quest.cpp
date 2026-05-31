#include <bits/stdc++.h>

using namespace std;

// 1912K. Kim's Quest - Codeforces

int main(){
	const long long mod = 998244353;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i<n;++i){
		cin >> a[i];
		a[i]%=2;
	}
	long long dp[2][2] = {{0,0},{0,0}};
	int cnte = 0,cnto = 0;
	long long ans = 0;
	for (int i = 0;i<n;++i){
		if (a[i]){
			ans += (dp[1][0] + dp[0][1]) % mod;
			ans %= mod;
			dp[1][1] += (dp[0][1] +cnto)%mod;
			dp[0][1] += (cnte + dp[1][0])%mod;
			cnto++;
		}
		else{
			ans += (dp[0][0] + dp[1][1]) % mod;
			ans %= mod;
			dp[0][0] += (cnte + dp[0][0])%mod;
			dp[1][0] += (dp[1][1] +cnto)%mod;
			cnte++;
			
		}
	}
	cout << ans << endl;
}
