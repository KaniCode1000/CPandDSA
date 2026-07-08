#include <bits/stdc++.h>
using namespace std;

// C. - 2238 codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<vector<int>> adj(n);
		for (int i = 0;i<n-1;++i){
			int u; cin >> u;
			adj[--u].push_back(i+1);
			adj[i+1].push_back(u);
		}		
		vector<int> color(n,0);
		long long ans = 0;
		auto dfs = [&](auto&& self,int v) -> int{
			color[v] = 1;
			int m = 0,sm = 0;
			for (int w: adj[v]){
				if (color[w] == 0){
					int value = self(self,w);
					if (value >= m){
						sm = m;
						m = value;
					}
					else if (value > sm){
						sm = value;
					}
				}
			}	
			ans += 1 + sm;
			return m+1;	
		};
		dfs(dfs,0);
		cout << ans << '\n';
	}
}
