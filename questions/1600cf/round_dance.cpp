#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<vector<int>> adj(n);
		vector<int> a(n);
		for (int i = 0;i<n;++i){
			int temp; cin >> temp;
			adj[i].push_back(--temp);
			adj[temp].push_back(i);
			a[i] = temp;
		}
		int numcc = 0;
		vector<int> cc(n,0);
		auto dfs = [&](int u,int num,auto &&self)->void{
			cc[u] = num;
			for (int v: adj[u]){
				if (cc[v] == 0)
					self(v,num,self);
			}	
		};
		int c2 = 0;
		for (int i = 0;i<n;++i){
			if (cc[i] == 0){
				dfs(i,++numcc,dfs);	
			}
			if (a[a[i]] == i){
				c2++;
			}
		}
		c2/=2;
		cout << min(c2,1) + numcc - c2 << " " << numcc << '\n';
		
	}
}
