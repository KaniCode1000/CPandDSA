#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<long long> b(n,0);
		vector<long long> a(n,0);
		map<long long,long long> freq;
		for (int i = 0;i<n;++i){
			cin >> b[i];
			freq[b[i]]++;
		}
		vector<pair<long long,long long>> dvals(freq.begin(),freq.end());
		if (dvals[0].first != 0){
			cout << -1 << '\n';
			continue;
		}
		map<long long,long long> actual;
		bool done = false;
		long long value = 0,prevvalue = 0;
		for (int i = 0;i<dvals.size()-1;++i){
			prevvalue = value;
			value = (dvals[i+1].first - dvals[i].first)/dvals[i].second;
			if (value*dvals[i].second + dvals[i].first != dvals[i+1].first || (prevvalue >= value && i!=0)){
				done = true;
				break;	
			}
			actual[dvals[i].first] = value;
		}
		if (done){
			cout << -1 << '\n';
			continue;
		}
		actual[dvals[dvals.size()-1].first] = value+1;
		for (int i = 0;i<n;++i){
			a[i] = actual[b[i]];
			cout << a[i] << " ";
		}	
		cout << '\n';
	}
}
