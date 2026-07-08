#include <bits/stdc++.h>
using namespace std;

// C. Ball in Berland - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int a,b,k;
		cin >> a >> b >> k;
		vector<int> couplesa(a,0),couplesb(b,0);
		for (int i = 0; i < k; ++i){
			int temp; cin >> temp;
			couplesa[temp-1]++;
		}
		for (int i = 0; i < k;++i){
			int temp; cin >> temp;
			couplesb[temp-1]++;
		}
		long long ans = (1LL*k*(k-1))/2;
		for (int i = 0;i<a;++i){
			ans -= (1LL*couplesa[i]*(couplesa[i]-1))/2;
		}
		for (int i = 0;i<b;++i){
			ans -= (1LL*couplesb[i]*(couplesb[i]-1))/2;
		}
		cout << ans << '\n';
	}	
}
