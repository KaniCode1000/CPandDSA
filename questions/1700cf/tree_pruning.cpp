#include <bits/stdc++.h>
using namespace std;

// C. Tree Pruning - Codeforces

int dfs(int u,int p,int dep,vector<vector<int>> &adj,vector<vector<int>> &dist){
	int mxdepth = dep;
	for (int v: adj[u]){
		if (v == p)
			continue;
		mxdepth = max(mxdepth,dfs(v,u,dep+1,adj,dist));
	}
	dist[dep].push_back(mxdepth);
	return mxdepth;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<vector<int>> adj(n);
		for (int i = 0;i<n-1;++i){
			int u,v;
			cin >> u >> v;
			adj[--u].push_back(--v);
			adj[v].push_back(u);
		}
		queue<pair<int,int>> q;
		vector<vector<int>> dist(n);	
		dfs(0,-1,0,adj,dist);
		int ans = n;
		multiset<int> s;
		for (int depth = 0;depth<n;++depth){
			for (int x: dist[depth]){
				s.insert(x);
			}
			while (!s.empty() && (*s.begin() < depth)){
				s.erase(s.begin());
			}
			ans = min(ans, n - (int)s.size());
		}	
		cout << ans << '\n';
	}
}	
