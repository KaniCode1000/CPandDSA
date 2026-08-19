#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<double> p(n);
	for (double &x: p) cin >> x;
	
	vector<vector<double>> dp(n+1,vector<double>(n+1,0));
	dp[0][0] = 1;
	
	for (int i = 1;i<=n;++i){
		for (int j = 0;j<=i;++j){
			dp[i][j] = (j?dp[i-1][j-1]*p[i-1]:0) + dp[i-1][j]*(1-p[i-1]);
		}
	}
	long double ans = 0;
	for (int j = n/2 + 1;j<=n;++j){
		ans += dp[n][j];	
	}
	cout << fixed << setprecision(10) << ans << '\n';
}
