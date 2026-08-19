#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	vector<int> h(n,0),dp(n,0);
	for (int i = 0;i<n;++i){
		cin >> h[i];
		dp[i] = 1e9;
	}
	dp[0] = 0;
	for (int i = 1;i<n;++i){
		for (int j = i-1; j >= max(0,i-k); --j){
			dp[i] = min(dp[j] + abs(h[i]-h[j]),dp[i]);	
		}
	}
	cout << dp[n-1] << '\n';
	
}
