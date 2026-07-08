#include <bits/stdc++.h>
using namespace std;

// D. minimum maximum on the path - Step3 Edu Codeforces
bool bfs(vector<vector<pair<int,long long>>> &adj,int t,int d,long long mx,vector<int> &path) {

	int n = adj.size();
	vector<int> dist(n, n);
	vector<int> par(n, -1);

	queue<int> q;
	q.push(0);
	dist[0] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (dist[v] == d) continue;

		for (auto [u, w] : adj[v]) {
			if (w > mx) continue;

			if (dist[u] > dist[v] + 1) {
				dist[u] = dist[v] + 1;
				par[u] = v;
				q.push(u);
			}
		}
	}

	if (dist[t] == n)
		return false;

	path.clear();
	for (int cur = t; cur != -1; cur = par[cur])
		path.push_back(cur);

	return true;
}

int main(){
	int n,m,d; cin >> n >> m >> d;
	vector<vector<pair<int,long long>>> adj(n);
	int a,b;
	long long c;
	for (int i = 0;i<m;++i){
		cin >> a >> b >> c;
		adj[--a].push_back({--b,c});
	}	
	long long l = 0,h = 1e9;
	long long ans = -1;
	vector<int> pseudo_path;
	while (l <= h){
		long long mid = l + (h-l)/2;
		bool found = bfs(adj,n-1,d,mid,pseudo_path);
		if (found){
			ans = mid;
			h  = mid-1;
		} 
		else{
			l = mid+1;
		}
	}
	if (ans == -1){
		cout << ans << '\n';
		return 0;
	}
	vector<int> path;
	bool meow = bfs(adj,n-1,d,ans,path);
	cout << path.size()-1 << '\n';	
	for (int i = path.size() - 1; i>=0;--i){
		cout << 1 + path[i] << " "; 
	}
	cout << '\n';
	
}
