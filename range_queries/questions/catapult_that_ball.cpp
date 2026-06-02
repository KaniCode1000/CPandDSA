#include <bits/stdc++.h>

using namespace std;

//B. Catapult that Ball - Codeforces Community Course Step1 question

int log2_floor(int i){
	return i ? __builtin_clzll(1) - __builtin_clzll(i) :-1;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,m;
		cin >> n >> m;
		vector<long long> heights(n);
		int K = log2_floor(n);
		long long st[K+1][n];
		for (int i = 0;i<n;++i){
			cin >> heights[i];
			st[0][i] = heights[i];
		}
		for (int i = 1;i<=K;++i){
			for (int j = 0;j + (1 << i) <= n;++j){
				st[i][j] = max(st[i-1][j],st[i-1][j + (1 << (i-1))]);
			}
		}
		long long total = 0;
		for (int i = 0;i<m;++i){
			int a,b;
			cin >> a >> b;
			if (a == b){
				total++;
				continue;
			}
			a--;
			b-=2;
			int val = log2_floor(b-a+1);
			long long maxi = max(st[val][a],st[val][1 + b - (1 << val)]);
			if (maxi == heights[a]){
				total++;
			}
		}
		cout << total << endl;
	}
}
