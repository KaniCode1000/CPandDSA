#include <bits/stdc++.h>

using namespace std;

// 1759 D. Make it Round - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		long long n,m; cin >> n >> m;
		long long x = n;
		int c2 = 0,c5 = 0;
		while (x%2 == 0){
			c2++;
			x/=2;
		} 
		while (x%5 == 0){
			c5++;
			x/=5;
		} 
		long long k = 1;
		while (k*2 <= m && c2 < c5){
			k *= 2;
			c2++;
		}
		while (k*5 <= m && c5 < c2){
			k *= 5;
			c5++;
		}

		while (k*10 <= m){
			k *= 10;
		}

		k *= m/k;
		cout << n*k << '\n';
		
	}
}
