#include <bits/stdc++.h>
using namespace std;

//D Edu 189 - Codeforces
#define int long long

long long mod = 998244353;

long long multiply(long long a, long long b,long long m){
	long long ans = 0;
	if (a==0)
		return ans;
	while (b)
	{
		if (b&1)
			ans = (ans + a) % m;
		a = (a+a)%m;
		b>>=1;
	}
	return ans;
}

int cnt(int n,int k){
	if (n<0){
		return 0;
	}
	return ((n+4-k)/4);
}

signed main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		long long n,x; cin >> n >> x;
		long long ans = 0;
		long long l1 = cnt(x-1,1) % mod;
		long long r1 = cnt(n,1) - cnt(x-1,1);
		r1 %= mod;
		long long l2 = (1+cnt(x-1,3)) % mod ;
		long long r2 = cnt(n,3) - cnt(x-1,3); 
		r2 %= mod;
		ans += multiply(l1,r1,mod);
		ans += multiply(l2,r2,mod);
		ans %= mod;
		cout << ans << '\n';
	}
}
