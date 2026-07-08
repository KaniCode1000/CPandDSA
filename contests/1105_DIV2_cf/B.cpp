#include <bits/stdc++.h>
using namespace std;

long long binexpo(long long a,long long b,long long m){
	a %=m;
	long long res = 1;
	while (b>0)
	{
		if (b&1)
			res = res*a % m;
		a = a*a % m;
		b >>= 1;
	}
	return res;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	long long mod = 998244353;
	while (t--){
		long long n,m,r,c;
		cin >> n >> m >> r >> c;
		long long sample = n*m - (n - r + 1)*(m- c+1);
		long long ans = binexpo(2,sample,mod);
		cout << ans << '\n';
	}
}
