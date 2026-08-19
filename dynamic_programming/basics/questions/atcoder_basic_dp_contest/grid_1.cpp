#include <bits/stdc++.h>
using namespace std;

int main(){
	const int mod = 1e9 + 7;
	int h,w; cin >> h >> w;
	vector<vector<int>> grid(h,vector<int>(w,1));
	vector<vector<long long>> dp(h,vector<long long>(w,0));
	for (int i = 0;i<h;++i){
		for (int j = 0;j<w;++j){
			char temp;
			cin >> temp;
			grid[i][j] = min(grid[i][j],temp-'#');	
		}
	}
	dp[0][0] = 1;

	for (int i = 0;i<h;++i){
		for (int j =0;j<w;++j){
			if (i && grid[i-1][j]){
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= mod;
			}
			if (j && grid[i][j-1]){
				dp[i][j] += dp[i][j-1];
				dp[i][j] %= mod;
			}
		}
	}
	
	cout << dp[h-1][w-1]%mod << '\n';
} 
