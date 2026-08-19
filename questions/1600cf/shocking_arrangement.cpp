#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<long long> ap,an;
		long long temp;
		for (int i = 0;i<n;++i){
			cin >> temp;
			if (temp <= 0){
				an.push_back(temp);
			}
			else{
				ap.push_back(temp);
			}
		}
		sort(an.begin(),an.end());
		sort(ap.begin(),ap.end(),greater<long long>());
		long long mini = *min_element(an.begin(),an.end());
		if (mini == 0){
			cout << "No" << '\n';
			continue;
		}	
		vector<long long> ans;
		long long tot = 0;
		int p = 0,q = 0;
		for (int i = 0;i<n;++i){
			if (p < ap.size() && (tot <= 0 || q == an.size())){
				ans.push_back(ap[p++]);	
				tot += ans.back();
			}
			else {
				ans.push_back(an[q++]);
				tot += ans.back();	
			}
		}
		cout << "Yes" << '\n';
		for (long long e: ans){
			cout << e << " ";
		}
		cout << '\n';
	}
}
