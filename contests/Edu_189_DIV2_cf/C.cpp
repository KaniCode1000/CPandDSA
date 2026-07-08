#include <bits/stdc++.h>
using namespace std;

//C Edu 189 - Codeforces

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string r1,r2; cin >> r1 >> r2;

		vector<int> dp(n+1);
		dp[0] = 0;
		if (r1[0] == r2[0]){
			dp[1] = 0;
		}
		else{
			dp[1] = 1;
		}
		int H,V;
		for (int i = 2;i<=n;++i){
			if (r1[i-1] == r2[i-1]){
				V = 0;
			}
			else{
				V = 1;
			}
			H = 0;
			if (r1[i-1] != r1[i-2]){
				H++;
			}
			if (r2[i-1] != r2[i-2]){
				H++;
			}
			dp[i] = min(dp[i-2]+H,dp[i-1]+V);
		}
		cout << dp[n] << '\n';
	}
}
