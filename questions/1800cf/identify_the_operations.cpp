#include <bits/stdc++.h>

using namespace std;

//1442 - B. Identify The Operations Codeforces

int main(){
	int t;
	cin >> t;
	long long mod = 998244353;
	while (t--){
		int n,k;
		cin >> n >> k;
		vector<int> a(n),b(k);
		vector<tuple<int,int,int>> status(n,{0,0,-1}); // zinda, index in a, order in b;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			get<1>(status[a[i]-1]) = i;
		}
		for (int i = 0;i<k;++i){
			cin >> b[i];
			get<2>(status[b[i]-1]) = i;
		}
		long long ans = 1;
		for (int i = 0;i<k;++i){
			int value = 0;
			int ind = get<1>(status[b[i]-1]);
			if (ind != 0){
				if (get<0>(status[a[ind-1]-1]) == 1 || get<2>(status[a[ind-1]-1]) < get<2>(status[b[i]-1])){
					value++;
				}
			}
			if (ind != n-1){
				if (get<0>(status[a[ind+1]-1]) == 1 || get<2>(status[a[ind+1]-1]) < get<2>(status[b[i]-1])){
					value++;
				} 
			}
			get<0>(status[b[i]-1]) = 1;
			ans *= value;
			if (!value){
				break;
			}
			ans %= mod;
		}
		cout << ans << endl;
			
	}
}
