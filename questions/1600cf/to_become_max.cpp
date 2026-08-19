#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		long long k; cin >> k;
		vector<long long> a(n);
		for (auto &x: a){
			cin >> x;
		}

		auto check = [&](long long m)->bool{
			for (int i = 0;i<n;++i){
				long long cost = 0;
				long long value = m;
				for (int j = i;j<n;++j){
					if (a[j] >= value){
						return true;
					}			
					cost += value-a[j];
					value--;
					if (cost > k){
						break;
					}
				}
			}
			return false;
		};
		
		long long maxy = *max_element(a.begin(),a.end());
		long long l = maxy, r = maxy + n;
		long long ans = maxy;
		while (l <= r){
			long long m = l + (r-l)/2;
			if (check(m)){
				l = m+1;
				ans = m;
			}
			else{
				r = m-1;
			}
		}
		cout << ans << '\n';
	}
}
