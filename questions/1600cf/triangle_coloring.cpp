#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int N = 3 * 1e5;

long long fact[N + 1], invFact[N + 1];

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;

    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[N] = binpow(fact[N], MOD - 2);

    for (int i = N; i >= 1; i--)
        invFact[i - 1] = invFact[i] * i % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

long long multiply(long long a, long long b,long long m)
{
	long long ans = 0;
	while (b)
	{
		if (b&1)
			ans = (ans + a) % m;
		a = (a+a)%m;
		b>>=1;
	}
	return ans;
}

int main(){
	int n; cin >> n;
	init();
	long long totways = 1;
	for (int i = 0;i<n/3;++i){
		long long w1,w2,w3;
		cin >> w1 >> w2 >> w3;
		long long a,b,c;
		a = min(min(w1,w2),w3);
		b = max(max(w1,w2),w3);
		c = w1 + w2 + w3 - a -b;
		if (w1 == w2 && w1 == w3){
			totways *= 3;
		}	
		else if (a == c){
			totways *= 2;
		}
		totways %= MOD;
	} 
	long long ans = multiply(nCr(n/3,n/6),totways,MOD);
	cout << ans << '\n';
}
