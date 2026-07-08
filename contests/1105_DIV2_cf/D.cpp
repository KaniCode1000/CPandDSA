#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n,d; cin >> n >> d;
		vector<long long> a(3*n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
			a[i+n] = a[i];
			a[i+2*n] = a[i];
		}	
		vector<long long> p(3*n);
		p[0] = a[0];
		for (int i = 1;i<3*n;++i){
			p[i] += p[i-1]+a[i];
		}
		long long tothap = 0;
		for (int i = n;i<2*n;++i){
			tothap += max(1LL*0,2*d*a[i] + a[i] - (p[i+d] - p[i-d-1]));
		}
		cout << tothap << '\n';
		
	}
}
