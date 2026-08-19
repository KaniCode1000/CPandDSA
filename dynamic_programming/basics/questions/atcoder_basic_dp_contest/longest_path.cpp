#include <bits/stdc++.h>
using namespace std;

void dfs(int u,vector<int> &dp, vector<vector<int>> &adj){
	if (dp[u])
		return;
	for (int v: adj[u]){
		if (dp[v] == 0)
			dfs(v,dp,adj);
		dp[u] = max(dp[u],1+dp[v]);
	}
	return;
}

int main(){
	int n,m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> dp(n,0);
	for (int i = 0;i<m;++i){
		int x,y;cin >> x >> y;
		adj[--x].push_back(--y);
	}
	int ans = 0;
	for (int i = 0;i<n;++i){
		dfs(i,dp,adj);
		ans = max(ans,dp[i]);
	}
	cout << ans << '\n';
	
}
