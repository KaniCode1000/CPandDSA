#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int t; cin >> t;
	vector<long long> dp(1e6+1,0);
	dp[1] = 1;
	dp[2] = 5;
	dp[3] = 10;
	long long val = 4;
	for (int i = 3;i<1415;++i){
		dp[val] = dp[val - i + 1] + (val)*(val);
		for (int j = val+1;j<val+i-1;++j){
			if (j > 1e6){
				break;
			}	
			dp[j] = dp[j - i + 1] + j*j + dp[j - i] - dp[j- i + 2 - i];
			
		}
		if (val + i -1 > 1e6)
			break;
		dp[val + i-1] = dp[val-1] + (val+i-1)*(val+i-1);
		val += i;
	}
	while (t--){
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}
