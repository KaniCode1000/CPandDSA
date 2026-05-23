#include <bits/stdc++.h>

using namespace std;
#define int long long

//1725 M Moving Both Hands Codeforces

pair<vector<vector<long long>>, vector<int>> dijkstra(int src, int n,vector<vector<tuple<int,int,int>>> &adj){

    priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> pq;

    long long infi = 1e18;

    vector<vector<long long>> keys(n, vector<long long>(2,infi));
    vector<int> prev(n, -1);

    keys[src][0] = 0;
    pq.emplace(0, src,0);

    while (!pq.empty()){

        auto [dist, u,state] = pq.top();
        pq.pop();

        if (dist > keys[u][state])
            continue;

        for (auto [v, weight,s] : adj[u]){
        	if (s == 0 && state == 1){
			continue;
		}    
		if (keys[u][state] + weight < keys[v][s]){

                	keys[v][s] = keys[u][state] + weight;
	                prev[v] = u;

	                pq.emplace(keys[v][s], v, s);
            }
        }
    }

    return {keys, prev};
}

signed main(){
	int n,m;
	cin >> n >> m;
	vector<vector<tuple<int,int,int>>> adj(n);
	for (int i = 0;i<m;i++){
		int a,b,w;
		cin >> a >> b >> w;
		adj[--a].push_back({--b,w,0});
		adj[b].push_back({a,w,1});
	}
	auto [dist,prev] = dijkstra(0,n,adj);
	for (int i = 1;i<n;++i){
		if (prev[i] == -1){
			cout << -1 << " ";
		}
		else{
			cout << min(dist[i][0],dist[i][1]) << " ";
		}
	}
	cout << endl;
}

