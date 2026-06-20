#include <bits/stdc++.h>
using namespace std;

//1692 G. 2^ Sort - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		vector <long long> a(n);
		for (long long &x: a) cin >> x;
		vector<int> bigger(n);
		for (int i = 1;i<n;++i){
			if (a[i-1] < 2*a[i]){
				bigger[i] = 1;
			}
			else{
				bigger[i] = 0;
			}
		}
		bigger[0] = 1;
		for (int i = 1;i<n;++i){
			bigger[i] += bigger[i-1];
		}
		int cnt = 0;
		for (int i = 0;i<n-k;++i){
			int j = i+k;
			int val = bigger[j]-bigger[i];
			if (val == k){
				cnt++;
			}
			
		}
		cout << cnt << '\n';
		
		
	}	
}
