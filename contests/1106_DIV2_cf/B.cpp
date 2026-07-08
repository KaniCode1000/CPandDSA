#include <bits/stdc++.h>
using namespace std;

// B. - 2238 codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		long long ans = 0;
		for (int i = 1;i<=n;++i){
			ans += 1LL*(n/i)*(n/i);
		}		
		cout << ans << '\n';
	}
}
