/* 
706 C Codeforces
*/

#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long> c(n);
	vector<string> str(n), rev(n);
	for (int i = 0;i<n;i++){
		cin >> c[i];
	}
	for (int i = 0;i<n;i++){
		cin >> str[i];
		rev[i] = str[i];
		reverse(rev[i].begin(),rev[i].end());
	}
	vector<vector<long long>> dp(n,vector<long long>(2,-1));
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for (int i = 1;i<n;i++){
		if (str[i-1] <= str[i]){
			dp[i][0] = dp[i-1][0];
		}
		if (str[i-1] <= rev[i]){
			if (dp[i-1][0] == -1){
				dp[i][1] = -1;
			}	
			else{
				dp[i][1] = dp[i-1][0] + c[i];
			}
		}
		if (rev[i-1] <= str[i]){
			if (dp[i][0] == -1){
				dp[i][0] = dp[i-1][1];
			}
			else if (dp[i-1][1] != -1){
				dp[i][0] = min(dp[i][0],dp[i-1][1]);
			}
		}
		if (rev[i-1] <= rev[i]){
			if (dp[i][1] == -1){
				if (dp[i-1][1] != -1){
					dp[i][1] = dp[i-1][1] + c[i];
				}
			}
			else{
				if (dp[i-1][1] != -1){
					dp[i][1] = min(dp[i-1][1] + c[i],dp[i][1]);
				}
			}
		}
	}
	long long ans;
	if (dp[n-1][0] == -1){
		ans = dp[n-1][1];
	}
	else if(dp[n-1][1] == -1){
		ans = dp[n-1][0];
	}
	else{
		ans = min(dp[n-1][0],dp[n-1][1]);
	}
	cout << ans << endl;
}
