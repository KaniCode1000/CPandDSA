#include <bits/stdc++.h>

using namespace std;

//1878E. Iva & Pav - Codeforces

int log2_floor(long long i){
	return i ? __builtin_clzll(1) - __builtin_clzll(i): -1;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		int K= log2_floor(n);
		vector<vector<long long>> st(K+1,vector<long long>(n));
		for (int i = 0;i<n;++i){
			cin >> a[i];
			st[0][i] = a[i];
		}
		for (int i = 1;i<=K;++i){
			for (int j = 0; j + (1 << i) <= n; ++j){
				st[i][j] = st[i-1][j] & st[i-1][j + (1 << (i-1))];
			}
		}
		int q;
		cin >> q;
		while (q--){
			int i,k;
			long long ans = -2;
			cin >> i >> k;
			i--;
			int high = n-1;
			int low = i;
			while (low <= high){
				int j = low + (high-low)/2;
				int value = log2_floor(j-i+1);
				long long val = st[value][i] & st[value][j - (1 << value) + 1];
				if (val >= k){
					ans = j;
					low = j+1;
				}
				else{
					high = j-1;
				}
			}
			cout << ans+1 << " ";
		}
		cout << '\n';
	}	


}
