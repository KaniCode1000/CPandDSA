#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> c(n);
	for (int i = 0;i<n;++i){
		cin >> c[i];
	}
	
	sort(c.begin(),c.end());
	
	vector<long long> dp_bfr(x+1,0),dp_cur(x+1,0);
	long long mod = 1e9 + 7;
	dp_bfr[0] = 1,dp_cur[0] = 1;
	
	for (int j = 0;j<n;++j){
		for (int i = c[j];i<=x;++i){
			dp_cur[i] = dp_cur[i-c[j]] + dp_bfr[i];
			dp_cur[i] %= mod;
		}
		dp_bfr = dp_cur;
	}
	
	cout << dp_bfr[x] << '\n';
}
