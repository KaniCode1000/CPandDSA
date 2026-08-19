#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	vector<int> dp(10,0);
	for (int i = 0;i<10;++i){
		for (int j = 0;j<10;++j){
			for (int k = 0;k<10;++k){
				if (i + j + k < 10){
					dp[i+j+k] += 1;
				}
				else{
					break;
				}
			}
		}
	}
	while (t--){
		string n; cin >> n;
		long long ans = 1;
		for (char i: n){
			ans *= dp[i-'0'];
		}
		cout << ans << '\n';
	}
}
