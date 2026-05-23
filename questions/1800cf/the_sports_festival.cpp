#include <bits/stdc++.h>

using namespace std;

//1509 C. The Sports Festival - Codeforces

int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];	
	}
	sort(a.begin(),a.end());
	vector<vector<long long>> dp(n,vector<long long>(n));	
	for (int i = 0;i<n;++i){
		dp[i][i] = 0;
	}
	for (int l = 2; l <= n;l++){
		for (int i = 0;i< n-l+1;++i){
			int j = i + l - 1;
			dp[i][j] = a[j] - a[i] + min(dp[i+1][j],dp[i][j-1]);
		}	
	}
	cout << dp[0][n-1] << endl;
}
