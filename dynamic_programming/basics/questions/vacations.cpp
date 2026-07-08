/* 
699 C codeforces
*/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> dp(n+1,vector<int>(3));
	int a[n+1];
	a[0] = 0;
	for (int i = 1;i<n+1;i++){
		dp[i] = {INT_MAX,INT_MAX,INT_MAX};
		cin >> a[i];
	}
	dp[0] = {0,0,0};
	for (int i = 1;i<n+1;i++){
		dp[i][0] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + 1;
		if (a[i] > 1){
			dp[i][1] = min({dp[i-1][0],dp[i-1][2]});
		}
		if (a[i] == 1 || a[i] == 3){
			dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
		}
	}
	cout << min({dp[n][0],dp[n][1],dp[n][2]}) << endl;
}
