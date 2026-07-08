#include <bits/stdc++.h>
using namespace std;

// E. - 2238 codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;
		int dp[n+1][n+1];
		for (int j = 0; j < n+1; ++j){
			for (int k = 0; k < n+1; ++k){
				dp[j][k] = INT_MAX;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < n;++i){
			int ndp[n+1][n+1];
			for (int f = 0; f < n+1;++f){
				for (int ss = 0; ss < 1+n; ++ss){
					ndp[f][ss] = INT_MAX;
				}
			}
			for (int f = 0; f < 1+i; ++f){
				for (int ss = 0; ss < i+1; ++ss){
					if (s[i] == 'T' || s[i] == 'N'){
						int ssd = max(0,ss-1);
						ndp[f][ssd] = min(ndp[f][ssd],dp[f][ss]);	
					}	
					if (s[i] == 'F' || s[i] == 'N'){
						ndp[f+1][ss+1] = min(ndp[f+1][ss+1],max(ss+1,dp[f][ss]));
					}
				}
			}
			swap_ranges(&dp[0][0], &dp[0][0] + (n+1)*(n+1), &ndp[0][0]);
		}
		int ans = 0;
		for (int i = 0; i < n+1; ++i){
			for (int j = 0; j < n+1; ++j){
				ans = max(ans,i - dp[i][j]);
			}
		}
		cout << ans << '\n'; 
	}
}
