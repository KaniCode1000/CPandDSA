#include <bits/stdc++.h>
using namespace std;

//D. Zero Remainder Array - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		long long k; cin >> k;
		vector<long long> a(n);
		map<long long,int> freq;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			a[i] %= k;
			freq[a[i]]++; 
		}
		long long ans = 0;
		for (auto &p: freq){
			if (p.first != 0)
				ans = max(ans,1 + (p.second - 1)*k + (k - p.first));	
		}
		cout << ans << '\n';
	}	
}
