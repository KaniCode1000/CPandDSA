#include <bits/stdc++.h>
using namespace std;

//1915G Codeforces
#define int long long
int dijkstra(int src, int n,vector<vector<pair<int,int>>> &adj, vector<int> &s){

    priority_queue<tuple<long long,int,int>,vector<tuple<int,long long,int>>,greater<tuple<int,long long,int>>> pq;

    long long infi = 1e18;

    vector<vector<long long>> keys(n, vector<int>(1001,infi));

    keys[src][s[src]] = 0;
    pq.emplace(0*s[src], src,s[src]);
    int mint = infi;
    while (!pq.empty()){

        auto [dist, u,slowness] = pq.top();
        pq.pop();

        if (dist > keys[u][slowness])
            continue;
	
	if (u == n-1){
		mint = min(mint,dist);
	}

        for (auto [v, weight] : adj[u]){
		int new_s = min(slowness,s[u]);
        	if (keys[u][slowness] + weight*new_s < keys[v][new_s]){
        		keys[v][new_s] = keys[u][slowness] + new_s*weight;
                	pq.emplace(keys[v][new_s], v,new_s);
		}
        }
    }

    return mint;
}

signed main(){
	int t;
	cin >> t;
	while (t--){
		int n,m;
		cin >> n >> m;
		vector<vector<pair<int,int>>> adj(n);
		vector<int> s(n);
		for (int i = 0;i<m;++i){
			int u,v,w;
			cin >> u >> v >> w;
			adj[--u].push_back({--v,w}); //cost, endpt
			adj[v].push_back({u,w});
		}
		for (int i = 0;i<n;i++){
			cin >> s[i];
		}
		int dist = dijkstra(0,n,adj,s);
		cout << dist << endl;
			
	}
}
