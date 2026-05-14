//2022 C - Codeforces Div2 Gerrymandering

#include <bits/stdc++.h>
using namespace std;

int result(int a,int b,int c){
	return (a&b) | (b&c) | (c&a);
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string r1;
		string r2;
		cin >> r1 >> r2;
		int dp[n+1][5];
		vector<vector<int>> row(2, vector<int>(n));
		for (int i = 0;i<n;i++){
			for (int j = 0;j<5;j++){
				dp[i][j] = -1;
			}
			if (r1[i] == 'A'){
				row[0][i] = 1;
			}
			else{
				row[0][i] = 0;
			}
			if (r2[i] == 'A'){
				row[1][i] = 1;
			}
			else{
				row[1][i] = 0;
			}
		}
		for (int j = 0;j<5;j++){
			dp[n][j] = -1;
		}
		dp[0][0] = 0;
		
		auto line = [&](int r,int c){
			return result(row[r][c],row[r][c+1],row[r][c+2]);
		};
		
		auto l = [&](int r,int c){
			return result(row[r][c],row[r][c+1],row[r+1][c]);
		};
		
		auto lr = [&](int r, int c){
			return result(row[r][c],row[r+1][c],row[r+1][c+1]);
		};

		auto lm = [&](int r,int c){
			return result(row[r][c],row[r][c+1],row[r+1][c+1]);
		};

		auto lrm = [&](int r,int c){
			return result(row[r][c+1],row[r+1][c],row[r+1][c+1]);
		};

		for (int i = 0;i<n;i++){
			if (dp[i][0] != -1){
				if (i+3 <= n){
					dp[i+3][0] = max(dp[i+3][0], dp[i][0] + line(0,i) + line(1,i));
				}
				if (i+2 <= n){
					dp[i+1][1] = max(dp[i+1][1], dp[i][0] + l(0,i));
					dp[i+1][2] = max(dp[i+1][2], dp[i][0] + lr(0,i));
				}
			}
			if (dp[i][1] != -1){
				if (i+2 <= n){
					dp[i+2][0] = max(dp[i+2][0],dp[i][1] + lrm(0,i));
				}
				if (i+4 <= n){
					dp[i+1][4] = max(dp[i+1][4], dp[i][1] + line(1,i));
				}
			}
			if (dp[i][2] != -1){
				if (i+2 <= n){
					dp[i+2][0] = max(dp[i+2][0],dp[i][2]+ lm(0,i));
				}
				if (i+4 <= n){
					dp[i+1][3] = max(dp[i+1][3],dp[i][2] + line(0,i));
				}
			}			
			if (dp[i][3] != -1){
				if (i+3 <= n){
					dp[i+2][2] = max(dp[i+2][2], dp[i][3] + line(1,i));
				}
			}
			if (dp[i][4] != -1){
				if (i+3 <= n){
					dp[i+2][1] = max(dp[i+2][1], dp[i][4] + line(0,i));
				}
			}
		}
		cout << dp[n][0] << endl;
	}
}
