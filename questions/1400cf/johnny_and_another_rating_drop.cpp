#include <bits/stdc++.h>
using namespace std;

// C. Johnny and Another Rating Drop - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		long long n; cin >> n;
		long long ans = 0;
		while (n != 0){
			ans += n;
			n >>= 1;
		}
		cout << ans << '\n';
	}
}
