#include <bits/stdc++.h>

using namespace std;

//1775D - Codeforces, math + bfs question

void bfs(int &n,int &s, int &u,const unordered_map<int,vector<int>> &factors, const unordered_map<int,vector<int>> &node_for_factor){
	queue<int> q;
	vector<bool> used(n+1,false);
	vector<int> d(1+n), p(n+1);

	q.push(s);
	used[s] = true;
	p[s] = -1;
	unordered_set<int> fac_used;
	while (!q.empty()) {
    		int v = q.front();
    		q.pop();
		for (int facs: factors.at(v)){
			if (fac_used.find(facs) != fac_used.end())
				continue;
			fac_used.insert(facs);
			for (int w: node_for_factor.at(facs)){
				if (!used[w]){
					used[w] = true;
					q.push(w);
					d[w] = d[v] + 1;
					p[w] = v;
				}
			}
		}	
	}

	//to display shortest path
	if (!used[u]) {
	   cout << -1 << endl;
	} 
	else {
		cout << d[u]+1 << endl;
		vector<int> path;
		for (int v = u; v != -1; v = p[v])
	   		path.push_back(v);
		reverse(path.begin(), path.end());
	   	for (int v : path)
		       	cout << v << " ";
	}
	cout << endl;
}

//returns vector of lowest prime factors array
vector<int> linear_sieve(int n){
	vector<int> lp(n+1,0);
	vector<int> pr;

	for (int i = 2;i<=n;i++){	
		if (lp[i] == 0){
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i*pr[j] <= n; ++j){
			lp[i*pr[j]] = pr[j];
			if (pr[j] == lp[i]){
				break;
			}
		}
	}
	return lp;
}

//returns factorisation of a number
vector<int> pfac(int n,const vector<int> &lp){
	set<int> uniquefacs;
	while (n>1){
		uniquefacs.insert(lp[n]);
		n /= lp[n];
	}
	return vector<int>(uniquefacs.begin(),uniquefacs.end());
}

int main(){
	int n;
	cin >> n;
	vector<int> nodes(n,0);
	for (int i = 0;i<n;++i){
		cin >> nodes[i];
	}
	auto maxy_it = max_element(nodes.begin(),nodes.end());
	int maxy = *maxy_it;
	int s,u;
	cin >> s >> u;
	if (s == u){
		cout << 1 << endl;
		cout << s << endl;
		return 0;
	}
	else if (maxy == 1){
		cout << -1 << endl;
		return 0;	
	}
	unordered_map<int,vector<int>> factors;
	unordered_map<int,vector<int>> nodes_for_facs;
	vector<int> lp;
	lp = linear_sieve(maxy);
	for (int i = 1;i<n+1;++i){
		factors[i] = pfac(nodes[i-1],lp);
		for (auto f: factors[i]){
			nodes_for_facs[f].push_back(i);
		}
	}
	bfs(n,s,u,factors,nodes_for_facs);
}
