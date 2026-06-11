#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
long long fact[MAXN], inv_fact[MAXN];

long long power(long long a, long long b){
	long long res = 1;
	while (b > 0){
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void precompute(){
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % MOD;
	inv_fact[MAXN-1] = power(fact[MAXN-1], MOD-2);
	for (int i = MAXN-2; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}

long long combo(long long n, long long r){
	if (r < 0 || r > n) return 0;
	return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}

void dfs(long long &ans, int l, int r, bool &doable,const vector<long long> &a){
	if (r < l || !doable) return;
	int val = l;
	for (int i = 0;i<(r-l+2)/2 ;++i){
		if (1LL*(val-l+1)*(r-val+1) == a[val]){
			break;
		}
		else{
			val = r-i;
			if (1LL*(val-l+1)*(r-val+1) == a[val]){
				break;
			}	
		}
		val = l+i+1;
	}
	
	if (1LL*(val-l+1)*(r-val+1) != a[val]){
		doable = false;
		return;
	}

	ans = ans * combo(r - l, val - l) % MOD;

	dfs(ans, l, val - 1, doable,a);
	dfs(ans, val + 1, r, doable,a);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
		}
		long long ans = 1;
		bool doable = true;
		dfs(ans, 0, n-1, doable,a);
		cout << (doable ? ans : 0LL) << '\n';
	}
}
