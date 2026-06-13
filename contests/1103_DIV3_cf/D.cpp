#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		vector<int> a(n),freq(n);
		vector<int> distinct;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			freq[a[i]-1]++;
			if (freq[a[i]-1] == 1){
				distinct.push_back(a[i]);	
			}
		}	
		sort(distinct.begin(),distinct.end());
		int siz = distinct.size();
		vector<int> dp(siz);
		for (int i = 0;i<siz;++i){
			dp[i] += freq[distinct[i]-1];
		}	
		bool done = false;
		if (dp[siz-1] % 2 == 0){
			cout << "YES" << '\n';
			continue;
		}
		for (int i = siz-2;i>=0;--i){
			if (distinct[i] + k >= distinct[i+1]){
				done = true;
				break;
			}
			if (dp[i] % 2 == 0){
				done = true;
				break;
			}	
		}

		if (done){
			cout << "YES" << '\n';
		}
		else{
			cout << "NO" << '\n';
		}
	}
	
}
