#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		multiset<long long> b;
		long long totsum = 0;
		for (int i = 0;i<n;++i){
			long long temp; cin >> temp;
			b.insert(temp);
			totsum += temp;
		}
		if (totsum <= 0){
			cout << -1 << '\n';
			continue;
		}
		
		long long pref = 0;
		vector<long long> a;
		for (int i = 0;i<n;++i){
			auto justbigger = b.upper_bound(-pref);	
			a.push_back(pref + *justbigger);
			pref += *justbigger;
			b.erase(justbigger);
		}
		
		for (int i = 0;i<n;++i){
			cout << a[i] << " ";
		}
		cout << '\n';
		
	}
}
