#include <bits/stdc++.h>

using namespace std;

//K. Kims Quest Codeforces

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i<n;++i){
		cin >> a[i];
		a[i] &= 1;
	}
	long long dp[2][2] = {{0,0},{0,0}};
	long long cnt = 0;
	long long oc = 0;
	oc += a[0] + a[1];
	dp[a[0]][a[1]] = 1;
	long long mod = 998244353;
	for (int i = 2;i<n;++i){
		if (a[i]){
			long long val = dp[0][1] + dp[1][0];
			val %= mod;
			cnt += val;
			cnt %= mod;		
		}
		else{
			long long val = dp[0][0] + dp[1][1];
			val %= mod;
			cnt += val;
			cnt %= mod;
		}
		dp[0][a[i]] += i-oc;
		dp[1][a[i]] += oc;
		oc += a[i];
	}
	cout << cnt << endl;
}
