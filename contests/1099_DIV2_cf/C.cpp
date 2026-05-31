#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
		}
		long long ans = LLONG_MAX;
		unordered_map<long long,pair<long long,long long>> dp;
		vector<long long> to_visit;
		unordered_set<long long> guys;
		long long mini = *min_element(a.begin(),a.end());
		if (mini == 1){
			to_visit.push_back(2);
			guys.insert(2);
		}
		else{
			while (mini != 1){
				to_visit.push_back(mini);
				guys.insert(mini);
				if (mini&1){
					mini++;
				}
				else{
					mini >>= 1;
				}
			}
		}
		to_visit.push_back(1);
		guys.insert(1);
		for (int i = 0;i<n;++i){
			long long e = a[i];
			long long length = 0;
			if (e == 1){
				dp[1].first++;
				dp[2].first++;
				dp[2].second += 1;
				continue;
			l}
			while (*lower_bound(to_visit.begin(),to_visit.end(),e) != e){
				if (e&1){
					e++;
					length++;
				}
				else{
					e>>=1;
					length++;
				}	
			}
			dp[e].first++;
			dp[e].second += length;
		}
		int index = to_visit.size()-1;
		for (int i = 1;i< to_visit.size();++i){
			dp[i].first += dp[i-1].first;
			dp[i].second += dp[i-1].first + dp[i-1].second;
		}
		for(long long k: to_visit){
			if (dp[k].first == n){
				ans = min(ans,dp[k].second);
			}
		}
		cout << ans << endl;
	}
}
