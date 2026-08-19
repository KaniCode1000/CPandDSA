#include <bits/stdc++.h>
using namespace std;

# define int long long

signed main(){
	int n,w; cin >> n >> w;
	vector<int> weight(n),value(n);
	vector<vector<int>> dp(n+1,vector<int>(w+1,0));
	for (int i = 0;i<n;++i){
		cin >> weight[i] >> value[i];
	}
	for (int i = 1;i<=n;++i){
		for (int j = 1;j<=w;++j){
			if (j < weight[i-1]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
			}
		}
	}
	cout << dp[n][w] << '\n';
}
