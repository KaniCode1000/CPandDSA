#include <bits/stdc++.h>
using namespace std;

// 625 A. Journey Planning - Codeforces

int main(){
	int n; cin >> n;
	vector<int> b(n);
	for (int &x: b) cin >> x;
	
	vector<long long> dp(n+1,0);
	dp[0] = 0;
	map<int,int> opt;
	for (int i = 0;i<n;++i){
		dp[i+1] = b[i] + dp[opt[b[i] - (i+1)]];
		opt[b[i]-(i+1)] = i+1;
	}
	long long ans = 0;
	for (int i = 0;i<=n;++i){
		ans = max(ans,dp[i]);	
	}
	cout << ans << '\n';
}
