#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		for (auto &x: a){
			cin >> x;
		}
		int ans = 1;
		for (int k = 1;k<n;++k){
			if (n % k != 0){
				continue;
			}
			int m = abs(a[0]-a[k]);	
			for (int i = 1;i<=n-k-1;++i){
				m = gcd(m,abs(a[i]-a[i+k]));
				if (m == 1)
					break;
			}	
			if (m != 1){
				ans++;
			}
		}
		cout << ans << '\n';
	}
}
