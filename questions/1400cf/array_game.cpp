#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		vector<long long> a(n);
		for (int i = 0;i<n;++i) cin >> a[i];
		long long mini = *min_element(a.begin(),a.end());
		if (k > 2){
			cout << 0 << '\n';
			continue;
		}
		vector<long long> diffs;
		for (int i = 0;i<n;++i){
			for (int j = i+1;j<n;++j){
				mini = min(mini,llabs(a[i]-a[j]));	
				diffs.push_back(llabs(a[i]-a[j]));
			}
		}
		if (k == 1){
			cout << mini << '\n';
			continue;
		}
		sort(a.begin(),a.end());
		for (long long val: diffs){
			auto it = upper_bound(a.begin(),a.end(),val) - a.begin();
			if (it != a.size()){
				mini = min(llabs(a[it]-val),mini);
			}
			if (it != 0){
				mini = min(llabs(a[it-1]-val),mini);
			}
		}	
		cout << mini << '\n';
	}
}
