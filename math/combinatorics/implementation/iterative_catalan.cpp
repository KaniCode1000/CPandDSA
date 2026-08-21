#include <bits/stdc++.h>
using namespace std;

// O(N) version of catalan numbers

const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
    long long res = 1;

    while (b) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

long long catalan(long long n) {
    vector<long long> fact(2 * n + 1);

    fact[0] = 1;

    for (int i = 1; i <= 2 * n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    long long numerator = fact[2 * n];
    long long denominator = fact[n] * fact[n] % MOD;
    denominator = denominator * (n + 1) % MOD;

    return numerator * modpow(denominator, MOD - 2) % MOD;
}

int main(){
	long long n;cin >> n;
	if (n & 1){
		cout << 0 << endl;
		return 0;
	}
	n >>= 1;	
	cout << catalan(n) << endl;	
}
