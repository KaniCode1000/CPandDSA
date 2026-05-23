#include <bits/stdc++.h>

using namespace std;

// 1462 F. The Treasure of The Segments - Codeforces

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<pair<long long,long long>> intervals(n);
		vector<long long> sorted_l(n);
		vector<long long> sorted_r(n);
		long long l,r;
		for (int i = 0;i<n;i++){
			cin >> l >> r;
			intervals[i] = {l,r};
			sorted_l[i] = l;
			sorted_r[i] = r;
		}
		sort(sorted_l.begin(),sorted_l.end());
		sort(sorted_r.begin(),sorted_r.end());
		long long mindel = LLONG_MAX;
		for (int i = 0;i<n;++i){
			long long start = intervals[i].first;
			long long end = intervals[i].second;
			long long bfr = lower_bound(sorted_r.begin(),sorted_r.end(),start) - sorted_r.begin();	
			long long after = n - (upper_bound(sorted_l.begin(),sorted_l.end(),end) - sorted_l.begin());
			mindel = min(mindel,bfr+after);
		}
		cout << mindel << endl;
	}
}
