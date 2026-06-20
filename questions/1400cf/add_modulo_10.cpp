#include <bits/stdc++.h>
using namespace std;

//1714 E. Add Modulo 10

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<long long> a(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
			a[i] += a[i]%10;
		}
		sort(a.begin(),a.end());
		bool done = true;
		for (int i = 0;i<n-1;++i){
			if (a[i] == a[i+1]){
				continue;
			}	
			if (a[i]%10 == 0){
				done = false;
				break;
			}
			if (a[i+1] % 10 == 0){
				done = false;	
				break;
			}
			while (a[i] % 10 != a[i+1]%10){
				a[i] += a[i]%10;
			}
			if ((a[i+1] - a[i]) % 20 != 0){
				done = false;
				break;
			}
		}
		cout << ((done)?("YES"):("NO")) << '\n';
	}
}
