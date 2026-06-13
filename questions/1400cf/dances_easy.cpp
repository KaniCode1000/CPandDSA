#include <bits/stdc++.h>
using namespace std;

// 1883 G1. Dances (Easy Version)

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,m; cin >> n >> m;
		vector<long long> a(n),b(n);
		a[0] = 1;
		for (int i = 1;i<n;++i){
			cin >> a[i];
		}
		for (int i = 0;i<n;++i) cin >> b[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int i = 0;
		int k = 0;
		for (int j = 0;j<n;++j){
			if (a[i] < b[j]){
				i++;
				k++;
			}
		}
		cout << n - k << '\n';
	}
}
