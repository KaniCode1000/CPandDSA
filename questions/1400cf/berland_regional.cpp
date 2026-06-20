#include <bits/stdc++.h>
using namespace std;

// 1519 C. Berland Regional - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<long long> u(n), s(n);
		vector<vector<long long>> uniteams(n);
		for (long long &x: u) cin >> x;
		for (int i = 0;i<n;++i){
			cin >> s[i];
			uniteams[u[i]-1].push_back(s[i]);
		}
		vector<long long> ans(n);

		for (int i = 1;i<n+1;++i){
			if (uniteams[i-1].size() != 0){
				sort(uniteams[i-1].begin(),uniteams[i-1].end(),greater<long long>());
				int m = uniteams[i-1].size();
				vector<long long> pref(m);
				pref[0] = uniteams[i-1][0];
				for (int j = 1;j<m;++j){
					pref[j] = uniteams[i-1][j] + pref[j-1];
				}
				for (int k = 0;k<m;++k){
					int used = (m/ (k+1)) * (k+1);
					ans[k] += pref[used-1];
				}
			}
		}
		for (long long k: ans){
			cout << k << " ";
		}
		cout << '\n';
	}
}
