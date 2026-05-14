#include <bits/stdc++.h>

using namespace std;
#define int long long
pair<vector<long long>, vector<int>> dijkstra(int src, int n,vector<vector<pair<int,int>>> &adj){

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

    long long infi = 1e18;

    vector<long long> keys(n, infi);
    vector<int> prev(n, -1);

    keys[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()){

        auto [dist, u] = pq.top();
        pq.pop();

        if (dist > keys[u])
            continue;

        for (auto [v, weight] : adj[u]){

            if (keys[u] + weight < keys[v]){

                keys[v] = keys[u] + weight;
                prev[v] = u;

                pq.emplace(keys[v], v);
            }
        }
    }

    return {keys, prev};
}

signed main(){
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n);
	for (int i = 0;i<m;i++){
		int a,b,w;
		cin >> a >> b >> w;
		adj[--a].push_back({--b,w});
		adj[b].push_back({a,w});
	}
	auto [dist,prev] = dijkstra(0,n,adj);
	auto val = n-1;
	vector<int> path;
	if (prev[n-1] == -1){
		cout << -1 << endl;
		return 0;
	}
	while (val != -1){		
		path.push_back(val);
		val = prev[val];
	}
	for (int i = path.size()-1;i>=0;i--){
		cout << path[i]+1 << " ";
	}
	cout << endl;
	return 0;
}
