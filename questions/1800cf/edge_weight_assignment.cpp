#include <bits/stdc++.h>

using namespace std;

//1338B. Edge Weight Assignment - Codeforces

void ldfs(vector<vector<int>> &adj,vector<int> &color,int v,vector<int> &dist){
	color[v] = 1;
	for (int u: adj[v]){
		if (color[u] == 0){
			dist[u] = dist[v] + 1;
			ldfs(adj,color,u,dist);
		}
	}
	color[v] = 2;
} 


void dfs(vector<vector<int>> &adj,vector<int> &color,int v,vector<int> &pred, vector<int> &leaves){
	color[v] = 1;
	bool leaf = true;
	for (int u: adj[v]){
		if (color[u] == 0){
			pred[u] = v;
			leaf = false;
			dfs(adj,color,u,pred,leaves);
		}
	}
	if (leaf){
		leaves.push_back(v);
	}
	color[v] = 2;
} 

int main(){
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> pred(n,-1),dist(n,0),leaves;
	for (int i = 0;i<n-1;++i){
		int a,b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	vector<int> color(n,0);
	dfs(adj,color,0,pred,leaves);
	int maxy = n-1;
	int mini = 1;
	if (adj[0].size() == 1){
		leaves.push_back(0);
		pred[0] = adj[0][0];
	}
	vector<bool> prevpar(n,false);
	vector<int> newcolor(n,0);
	ldfs(adj,newcolor,leaves[0],dist);
	for (int leaf: leaves){
		if (prevpar[pred[leaf]] == false){
			prevpar[pred[leaf]] = true;
		}
		else{
			maxy -= 1;
		}
		mini = max(mini, (dist[leaf]%2)*2 + 1);
	}
	cout << mini << " " << maxy << endl;
}
