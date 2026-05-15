#include <bits/stdc++.h>

using namespace std;

//1824 B1 Codeforces
# define int long long

int dfs(int n,int v,int &value,vector<vector<int>> &adj,vector<int> &color) {
    color[v] = 1;
    int count = 1;
    for (int u : adj[v]){
        if (color[u] == 0){
		count += dfs(n,u,value,adj,color);
	}
    }
    value += count*(n-count);
    color[v] = 2;
    return count; 
}
long long binexpo(long long a,long long b,long long m){
  a %=m;
  long long res = 1;
  while (b>0)
  {
    if (b&1)
      res = res*a % m;
    a = a*a % m;
    b >>= 1;
  }
  return res;
}
signed main(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>> adj(n);
	vector<int> color(n,0);	
	for (int i = 0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	if (k != 2){
		cout << 1 << endl;
	}
	else{
		int ans = 0;
		dfs(n,0,ans,adj,color);
		int nc2 = (n*(n-1))/2;
		int mod = 1e9 + 7;
		ans += nc2;
		int g = gcd(ans,nc2);
		int p = ans/g;
		int q = nc2/g;		
		q = binexpo(q,mod-2,mod);
		q = q%mod;
		p = p%mod;
		ans = p*q % mod;
		cout << ans << endl;
	}
}

