#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> h(n);
		for (int i = 0;i<n;++i){
			cin >> h[i];
		}
		vector<long long> ans(n);

		for (int i = 0;i<n;++i){
			vector<long long> L(n-1),R(n-1);
			L[0] = h[i];
			R[n-2] = h[(i-1 + n)%n];
			for (int l = 1;l<n-1;++l){
				L[l] = max(L[l-1],h[(l+i)%n]);
			}
			for (int r = n-3;r >=0;--r){
				R[r] = max(R[r+1],h[(r+i+1)%n]);
			}
			long long ansrn = 0;
			for (int k = 0;k<n-1;++k){
				ansrn += min(L[k],R[k]);
			}
			ans[i] = ansrn;
		}
		
		for (int i = 0;i<n;++i){
			cout << ans[i] << " ";
		}
		cout << '\n';
		
	}	
}

