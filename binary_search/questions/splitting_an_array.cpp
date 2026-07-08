#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	vector<long long> a(n);
	for (long long &x: a){
		cin >> x;
	}
	auto good = [&](long long m) -> bool {	
		int tk = 1;
		long long summy = 0;	
		for (int i = 0;i<n;++i){
			if (a[i] > m){
				return false;
			}  
			else if (a[i] + summy > m){
				tk += 1;
				summy = a[i];
			}
			else{
				summy += a[i];
			}
		}
		if (tk <= k){
			return true;
		}
		return false;
	};
	long long l = *max_element(a.begin(),a.end()), h = n * 1e9;
	long long ans = h;
	while (l <= h){
		long long m = l + (h-l)/2;
		if (good(m)){
			h = m-1;
			ans = m;
		}
		else{
			l = m+1;
		}
	}
	cout << ans << '\n';
}
