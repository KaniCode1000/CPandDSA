#include <bits/stdc++.h>

using namespace std;

int log2_floor(long long i){
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		int K = log2_floor(n); 
		long long st[K+1][n];
		for (int i = 0;i<n;++i){
			cin >> a[i];	
			st[0][i] = a[i];
		}
		for (int i = 1;i<=K;++i){
			for (int j = 0; j + (1 << i) <= n; ++j){
				st[i][j] = min(st[i-1][j],st[i-1][j + (1 << (i-1))]);
			}
		}
		int q;
		cin >> q;
		while (q--){
			int i,j;
			cin >> i >> j;
			int value = log2_floor(j-i+1); //largest power of 2 < length of range
			long long mini = min(st[value][i],st[value][j- (1<<value) + 1]);
			cout << mini << '\n';
		}
	}
}
