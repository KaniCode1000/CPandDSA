#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> a(n),b(n),c(n);
	for (int i = 0;i<n;++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<array<int,3>> dp(n+1);
	dp[0] = {0,0,0};
	for (int i = 1;i<=n;++i){
		dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a[i-1];
		dp[i][1] = b[i-1] + max(dp[i-1][2],dp[i-1][0]);
		dp[i][2] = c[i-1] + max(dp[i-1][0],dp[i-1][1]);
	} 
	int ans = dp[n][0];
	ans = max(ans,max(dp[n][1],dp[n][2]));
	cout << ans << '\n';
}
