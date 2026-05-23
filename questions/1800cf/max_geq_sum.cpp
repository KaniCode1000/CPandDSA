#include <bits/stdc++.h>

using namespace std;

//D. Max GEQ Sum - Codeforces 1691

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
		}
		vector<pair<long long,long long>> dp(n);
		dp[0] = {0,a[0]};
		bool done = true;
		for (int i = 1;i<n;++i){
			if (a[i] > dp[i-1].second){
				dp[i] = {max((long long) 0,dp[i-1].first+ 2*dp[i-1].second-a[i]),a[i]};
			}	
			else {
				if (0 > dp[i-1].first + a[i]){
					dp[i] = {0,a[i]};
				}
				else {
					dp[i] = {dp[i-1].first + a[i],dp[i-1].second};
				}
			}
			if (dp[i].first > 0){
				done = false;
				break;
			}
		}
		cout << ((done)?"YES\n":"NO\n");
	}
}
