#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,h; cin >> n >> h;
	long long ans = 0;
	vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
	dp[0][0] = 1;
	for (int i = 1;i<=n;++i){
		for (int j = 1;j<=i;++j){
			for (int k = 1;k<=i;++k){
				for (int z = 0;z <= j-1;++z){
					if (z == j-1){
						dp[i][j] += dp[k-1][j-1]*dp[i-k][z];
						continue;
					}
					dp[i][j] += dp[k-1][j-1]*dp[i-k][z] + dp[i-k][j-1]*dp[k-1][z];
				}			 
			}	
		} 
	}
	for (int j = h;j<=n;++j){
		ans += dp[n][j];
	}
	cout << ans << endl;
}
