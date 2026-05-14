#include <bits/stdc++.h>

using namespace std;

#define int long long

pair<vector<int>,vector<int>> dijkstra(int src,int n,vector<vector<pair<int,int>>> adj,vector<int> horses){
	long long infi = 1e18;
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
	vector<long long> keys1(n,infi);
	vector<long long> keys0(n,infi);
	if (horses[src] == 0){
		pq.emplace(0,src,0);
		keys0[src] = 0;
	}
	else{
		pq.emplace(0,src,1);
		keys1[src] = 0;	
	}
	while (!pq.empty()){
		tuple<int,int,int> w = pq.top();
		pq.pop();
		int wstar = get<1>(w);

		if ((get<0>(w) > keys0[wstar] && get<2>(w) == 0) || (get<0>(w) > keys1[wstar] && get<2>(w) == 1))
			continue;
		
		for (auto edge: adj[wstar]){
			int v = edge.first;
			int weight = edge.second;
			if (get<2>(w) == 1){ 
				if (keys1[wstar] + weight/2 < keys1[v]){
					keys1[v] = keys1[wstar] + weight/2;
					pq.emplace(keys1[v],v,1);
				}
			}
			else if(horses[wstar] == 1 && keys0[wstar] + weight/2 < keys1[v]){
				keys1[v] = keys0[wstar] + weight/2;
				pq.emplace(keys1[v],v,1);
			}
			else if (keys0[wstar] + weight < keys0[v] && horses[wstar] == 0){
				keys0[v] = keys0[wstar] + weight;
				pq.emplace(keys0[v],v,0);
			}
		}
	}
	
	return {keys0,keys1};
}



signed main(){
	int t;
	cin >> t;
	while (t--){
		int n,m,h;
		cin >> n >> m >> h;
		vector<int> hv(n,0);
		vector<vector<pair<int,int>>> adj(n);
		for (int i = 0;i<h;i++){
			int a;
			cin >> a;
			a--;
			hv[a] = 1;
		}
		for (int i = 0;i<m;i++){
			int u,v,w;
			cin >> u >> v >> w;
			adj[--u].push_back({--v,w});
			adj[v].push_back({u,w});
		}
		auto [ks0,ks1] = dijkstra(0,n,adj,hv);
		auto [kd0,kd1] = dijkstra(n-1,n,adj,hv);
		int dist = 1e18;
		bool path = false;
		for (int i = 0;i<n;i++){
			int a = ks0[i];
			int b = ks1[i];
			int c = kd0[i];
			int d = kd1[i];
			dist = min({dist,max(a,c),max(a,d),max(b,c),max(b,d)});
		}
		if (dist == 1e18){
			cout << -1 << endl;
		}
		else{
			cout << dist << endl;
		}
			
	}	
}
