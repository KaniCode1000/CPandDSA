#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	long long mod = 998244353;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		int totxor = 0;
		for (int i = 0; i<n;++i){
			cin >> a[i];
			totxor ^= a[i];
		}
		if (n == 1){
			cout << 0 << '\n';
			continue;
		}
		else if (totxor == 0){
			cout << 1 << '\n';
			continue;
		}
		else{
			long long ans = 0;
			for (int i = 0;i<n;++i){
				if ((totxor ^ a[i]) < a[i]){
					ans++;
				}
			}
			cout << ans << '\n';
		}
			
	}
}
