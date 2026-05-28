#include <bits/stdc++.h>
using namespace std;

#define int long long

//1283D. Christmas Tree - Codeforces

pair<int,vector<int>> bfs(vector<int> &x,int enough){
	queue<pair<int,int>> q;
	set<int> used;	
	for (int s: x){
		q.push({s,0});
		used.insert(s);
	}
	int adj[2] = {-1,1};
	long long res = 0;
	long long value = 0;
	vector<long long> soln;
	while (!q.empty()) {
	        pair<int,int> meow = q.front();
		int v = meow.first;
		int d = meow.second;
        	q.pop();
       		for (int z : adj) {
			int w = z + v;
        		if (used.find(w) == used.end()) {
        	        	used.insert(w);
                		q.push({w,d+1});
				res += d+1;
				value++;
				soln.push_back(w);
			}
			if (value == enough){
				break;
			}
        	}
		if (value >= enough){
			break;
		}
  	}	
	return {res, soln};
}

signed main(){
	int n,m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i = 0;i<n;++i){
		cin >> x[i];
	}
	pair<int,vector<int>> ans;
	ans = bfs(x,m);
	cout << ans.first << endl;
	for (int i: ans.second){
		cout << i << " ";
	}
	cout << endl;
}
