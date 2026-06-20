#include <bits/stdc++.h>

using namespace std;

// 1771 B. Hossam and Friends - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n,m; cin >> n >> m;
		long long ans = 0;
		int u,v;	
		vector<int> counted(n);
		for (int i = 0;i<n;++i){
			counted[i] = n;
		}
		for (int i =0;i<m;++i){
			cin >> u >> v;
			counted[min(u,v)-1] = min(counted[min(u,v)-1],max(u,v)-1);
		}
		for (int i = n-2;i>=0;--i){
			counted[i] = min(counted[i],counted[i+1]);
		}
		for (int l = 0;l<n;++l){
			ans += counted[l] - l;
		}
		cout << ans << '\n';
	}	
}
