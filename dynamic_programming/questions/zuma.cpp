/*
607 B - Zuma
Codeforces
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0;i<n;i++){
		cin >> x[i];
	}
	vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
	for (int i = 0;i<n-1;i++){
		dp[i][i] = 1;
		if (x[i] == x[i+1]){
			dp[i][i+1] = 1;	
		}
		else{
			dp[i][i+1] = 2;
		}
	}
	dp[n-1][n-1] = 1;
	for (int i = 3;i<n+1;i++){
		int last = n-i;
		for (int j = 0;j<last+1;j++){
			int k = j+i-1;
			dp[j][k] = INT_MAX;
			if (x[j] == x[k]){
				dp[j][k] = dp[j+1][k-1];
			}
			for (int z = j;z<k;z++){
				dp[j][k] = min(dp[j][k], dp[j][z] + dp[z+1][k]);
			}
		}
	}	
	cout << dp[0][n-1] << endl;	
}
