#include <bits/stdc++.h>

using namespace std;

//1517 D. Explorer Space - Codeforces

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	pair<int,int> l[n][m];
	for (int i = 0;i<n;++i){
		for (int j = 0;j<m;++j){
			l[i][j] = {0,0};
		}
	}
	for (int i = 0;i<n;++i){
		for (int j = 0;j<m-1;++j){
			cin >> l[i][j].first;
		}
	}
		
	for (int i = 0;i<n-1;++i){
		for (int j = 0;j<m;++j){
			cin >> l[i][j].second;
		}
	}
	if (k%2){
		for (int i = 0;i<n;++i){
			for (int j=0;j<m;++j){
				cout << -1 << " ";
			}
			cout << endl;
		}
	}
	else{
		int INF = 1e9;
		int dp[k/2 + 1][n][m];
		for (int i = 0;i<n;++i){
			for (int j =0;j<m;++j){
				dp[0][i][j] = 0;
			}
		}
		for (int step = 1;step <= k/2;++step){
			for (int i = 0;i<n;++i){
				for (int j = 0;j<m;++j){
					dp[step][i][j] = INF;
					if (i > 0){
						dp[step][i][j] = min(dp[step][i][j], dp[step-1][i-1][j] + l[i-1][j].second); 
					}
					if (i < n-1){
						dp[step][i][j] = min(dp[step][i][j], dp[step-1][i+1][j] + l[i][j].second); 
					}
					if (j > 0){
						dp[step][i][j] = min(dp[step][i][j], dp[step-1][i][j-1] + l[i][j-1].first);
					}
					if (j < m-1){
						dp[step][i][j] = min(dp[step][i][j],dp[step-1][i][j+1] + l[i][j].first);
					}
				}
			}
		}
		for (int i = 0;i<n;++i){
			for (int j=0;j<m;++j){
				cout << 2*dp[k/2][i][j] << " ";
			}
			cout << endl;
		}

	}
	
}
