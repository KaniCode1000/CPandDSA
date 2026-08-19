#include <bits/stdc++.h>
using namespace std;

# define int long long

signed main(){
	int n,w; cin >> n >> w;
	vector<int> weight(n),value(n);
	for (int i = 0;i<n;++i){
		cin >> weight[i] >> value[i];
	}
	int v = 0;
	for (int i = 0;i<n;++i){
		v += value[i];
	} 	
	vector<vector<int>> dp(n+1,vector<int>(v+1,1e12));
	dp[0][0] = 0;
	for (int i = 1;i<=n;++i){
		for (int j = 0;j<=v;++j){
			dp[i][j] = dp[i-1][j];
			if (j >= value[i-1]){
				dp[i][j] = min(dp[i][j],dp[i-1][j-value[i-1]] + weight[i-1]);
			}
		}
	}
	for (int val = v; val >= 0;--val){
		if (dp[n][val] <= w){
			cout << val << '\n';
			break;
		}
	}
}
