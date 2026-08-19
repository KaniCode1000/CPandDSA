#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t; cin >> s >> t;
	int a = s.size(),b = t.size();
	vector<vector<int>> dp(a+1,vector<int>(b+1,0));
	for (int i = 1;i<=a;++i){
		for (int j = 1;j<=b;++j){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			dp[i][j] = max(dp[i][j],dp[i-1][j-1]+((s[i-1] == t[j-1])?(1):(0)));	
		}
	}
	int i = a,j = b;
	vector<char> ans;
	while (i > 0 && j > 0){
		if (s[i-1] == t[j-1]){
			ans.push_back(s[i-1]);
			i--;
			j--;
		}
		else{
			if (dp[i][j-1] > dp[i-1][j]){
				j--;
			}
			else{
				i--;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	for (char i: ans){
		cout << i;
	}
	cout << '\n';
}
