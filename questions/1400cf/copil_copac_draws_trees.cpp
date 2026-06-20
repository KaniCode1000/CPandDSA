#include <bits/stdc++.h>
using namespace std;

// 1830 A. Copil Copac Draws Trees - Codeforces

void dfs(vector<int> &color,int weight,int v, vector<int> &dc, const vector<vector<pair<int,int>>> &adj){
	color[v] = 1;
	for (pair<int,int> u: adj[v]){
		if (color[u.first] == 0){
			dc[u.first] = dc[v] + ((weight > u.second) ? (1):(0));
			dfs(color,u.second,u.first,dc,adj);
		}
	}	
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> color(n);
		vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
		vector<int> draw_cycle(n);
		draw_cycle[0] = 1;
		for (int i = 0;i<n-1;++i){
			int u,v; cin >> u >> v;
			adj[--u].push_back({--v,i});
			adj[v].push_back({u,i});
		}
		dfs(color,-1,0,draw_cycle,adj);
		int maxy = 1;
		for (int i: draw_cycle){
			maxy = max(i,maxy);
		}
		cout << maxy << '\n';
			
	}
}
