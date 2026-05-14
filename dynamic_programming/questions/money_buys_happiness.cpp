#include <bits/stdc++.h>

using namespace std;

// Money Buys Happiness - 1974E Codeforces

int main(){
	int t;
	cin >> t;
	while (t--){
		long long m,x;
		cin >> m >> x;
		vector<long long> c(m),h(m);
		long long haplim = 1;
		for (int i = 0;i<m;++i){
			cin >> c[i] >> h[i];
			haplim += h[i];
		}
		vector<vector<long long>> dp(m+1,vector<long long>(haplim));
		for (int i = 0; i<m+1;i++){
			dp[i][0] = 0;
		}
		for (int i = 0;i<haplim;i++){
			dp[0][i] = 1e18;
		}
		dp[0][0] = 0;
		long long maxhap = 0;
		for (long long i = 1;i<m+1;++i){
			for (long long j = 1;j<haplim;++j){
				if (dp[i-1][max((long long) 0, j-h[i-1])] + c[i-1] <= x*(i-1)){
					dp[i][j] = min(dp[i-1][j], dp[i-1][max((long long) 0,j-h[i-1])] + c[i-1]);
					maxhap = max(maxhap,j);
				}
				else{
					dp[i][j] = dp[i-1][j]; 
				}
			}
		}
		cout << maxhap << endl;
	}
		
}
