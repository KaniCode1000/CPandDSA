#include <bits/stdc++.h>

using namespace std;

// 1401D. Maximum Distributed Tree - Codeforces

vector<vector<int>> adj;
int n; 
vector<int> subnodes;
vector<int> color;

int dfs(int v) {
	color[v] = 1;
   	for (int u : adj[v])
        	if (color[u] == 0)
            		subnodes[v] += dfs(u) + 1;
  	color[v] = 2;
	return subnodes[v];
}

int main(){
	int t;
	cin >> t;
	int u,v;
	while (t--){
		cin >> ::n;
		adj.assign(n,{});
		color.assign(n,0);
		subnodes.assign(n,0);
		for (int i = 0; i < ::n -1;++i){
			cin >> u >> v;
			::adj[--u].push_back(--v); 
			::adj[v].push_back(u);
		}	
		int m;
		cin >> m;
		long long mod = 1e9 + 7;
		vector<long long> p(m);
		for  (int i = 0;i<m;++i){
			cin >> p[i];
		}
		sort(p.begin(),p.end());
		vector<long long> evals;
		dfs(0);
		for(int i = 0;i<::n;++i){
			for (auto edge: adj[i]){
				if (edge < i){
					continue;
				}
				int temp = min(subnodes[i],subnodes[edge]) + 1;
				evals.push_back((1LL* temp)*(1LL*(n-temp)));			
			}
		}
		sort(evals.begin(),evals.end());		
		long long ans = 0;  
		while (m > n-1){
			p[m-2]*= p[m-1];
			p[m-2] %= mod;
			p.pop_back();
			m--;
		}
		int bigp = m-1;
		for (int i = n-2;i>=0;--i){
			if (bigp != -1){
				ans += p[bigp--]*evals[i];
			}
			else{
				ans += evals[i];
			}
			ans%=mod;
		}
		cout << ans << endl;
	}
}
