#include <bits/stdc++.h>

using namespace std;

//1437 C. Chef Monocarp - Codeforces

int main(){
	int q;
	cin >> q;
	int infi = 1e5;
	while (q--){
		int n;
		cin >> n;
		vector<int> t(n);
		for (int i = 0; i <n;++i){
			cin >> t[i];
		}
		sort(t.begin(),t.end());
		int time = n + n/2;
		int dp[n+1][time+1];
		for (int i = 0;i<time+1;++i){
			dp[0][i] = 0;
			for (int j = 1;j < n+1;++j){
				dp[j][i] = infi;
			}
		}
		for (int i = 1;i<n+1;++i){
			for (int j = 1; j < time + 1; ++j){
				dp[i][j] = min(dp[i][j-1],dp[i-1][j-1] + abs(t[i-1] - j));
			}
		}
		cout << dp[n][time] << endl;
	}
}
