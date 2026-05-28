#include <bits/stdc++.h>
using namespace std;

// 1286 B. Numbers on a Tree - Codeforces

void dfs(int v, vector<vector<int>> &adj, vector<int> &color, vector<int> &subtree,const vector<int> &c,bool &done,vector<int> &order){
	color[v] = 1;
	if (done){
		return;
	}
	for (int u: adj[v]){
		dfs(u,adj,color,subtree,c,done,order);
		subtree[v] += subtree[u] + 1;
	}
	if (subtree[v] < c[v]){
		done = true;
	}
	color[v] = 2;
	if (done){
		return;
	}
	order.insert(order.begin() + c[v],v+1);
} 

int main(){
	int n;
	cin >> n;
	vector<int> p(n),c(n),color(n,0),subtree(n,0),order;
	vector<vector<int>> adj(n);
	int root;
	for (int i = 0;i<n;++i){
		cin >> p[i] >> c[i];
		if (p[i] == 0){
			root = i+1;	
			continue;
		}	
		adj[p[i]-1].push_back(i);
	}	
	bool done = false;
	dfs(root-1,adj,color,subtree,c,done,order);
	if (done){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		vector<int> values(n,0);
		int v = 1;
		for (int i: order){
			values[i-1] = v++;
		}
		for (int i = 0;i<n;++i){
			cout << values[i] << " ";
		}
		cout << endl;
	}
} 
