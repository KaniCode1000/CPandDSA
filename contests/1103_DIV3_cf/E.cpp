#include <bits/stdc++.h>
using namespace std;

int log2_floor(long long i){
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		vector<int> latest(n+1);
		int K = log2_floor(n);
		vector<long long> stmin(K+1,vector<long long>(n)),stmax(K+1,vector<long long>(n));
		vector<int> prev(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
			prev[i] = n;
			latest[i] = n;
			stmin[0][i] = a[i];
			stmax[0][i] = a[i];
		}
		latest[n] = n;
		latest[a[0]] = 0;
		vector<long long> st(K+1,vector<long long>(n));
		for (int i = 1;i<n;++i){
			prev[i] = latest[a[i]];
			latest[a[i]] = i;	
			st[0][i] = prev[i];
		}
		for (int i = 0;i<=K;++i){
			for (int j = 0;j + (1 << i) <= n;++j){
				st[i][j] = max(st[i-1][j],st[i-1][j+ (1 << (i-1))]);
				stmax[i][j] = max(st[i-1][j],st[i-1][j+ (1 << (i-1))]);
				stmin[i][j] = min(st[i-1][j],st[i-1][j+ (1 << (i-1))]);
			}
		}
		vector<vector<int>> lefts,rights;
		for (int l = 1;l<n/2;++l){
			deque<int> dq;
			for (int i = 0;i<n;++i){
					
			}
		}
		
	}
}
