#include <bits/stdc++.h>
using namespace std;

//A Wide Wide Graph - 1805 D Codeforces

void dfs(vector<vector<int>> &adj, int src,int dist, vector<int> &color,int &maxdist,int &dest,vector<int> &distances){
	color[src] = 1;
	distances[src] = dist;
	if (dist > maxdist){
		maxdist = dist;
		dest = src;
	}
	for (int v: adj[src]){
		if (color[v] == 0)
			dfs(adj,v,dist+1,color,maxdist,dest,distances);
	}
}

pair<int,int> diameter(vector<vector<int>> &adj,int n){
	int maxdist = 0;
	vector<int> distances(n,0);
	int d1,d2;
	d1 = 0;
	d2 = 0;
	vector<int> color(n,0);
	dfs(adj,0,0,color,maxdist,d1,distances);
	maxdist = 0;
	for (int i = 0;i<n;i++){
		color[i] = 0;
	}
	dfs(adj,d1,0,color,maxdist,d2,distances);
	return {d1,d2};
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	auto [d1,d2] = diameter(adj,n);
	vector<int> distances1(n,0);
	vector<int> distances2(n,0);
	vector<int> color(n,0);
	int maxdist = 0;
	int dest = 0;
	dfs(adj,d1,0,color,maxdist,dest,distances1);
	maxdist = 0;
	dest = 0;
	for (int i = 0;i<n;++i){
		color[i] = 0;
	}
	dfs(adj,d2,0,color,maxdist,dest,distances2);
	for (int i = 0;i<n;i++){
		distances1[i] = max(distances1[i],distances2[i]);
	}
	sort(distances1.begin(),distances1.end());
	for (int i = 1;i<n+1;++i){
		auto val = lower_bound(distances1.begin(),distances1.end(),i);
		int value = val - distances1.begin();
		cout << min(1+value,n) << " ";
	}
	cout << endl;
}	
