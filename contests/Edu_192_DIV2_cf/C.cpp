#include <bits/stdc++.h>
using namespace std;

//Edu 192 C - Codeforces

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		vector<int> a(n),tempm;
		vector<pair<int,int>> mc;
		cin >> a[0];
		int prev = a[0];
		tempm.push_back(1);
		int last = 0;
		for (int i = 1;i<n;++i){
			cin >> a[i];
			if (prev == a[i]){
				tempm[last]++;
			}
			else{
				tempm.push_back(1);
				last++;
			}
			prev = a[i];
		}
		if (k==0){
			cout << 1 << '\n';
			continue;}
		sort(tempm.begin(),tempm.end());	
		mc.push_back({tempm[0],1});
		prev = tempm[0];
		int lasty = 0;
		for (int i = 1;i<last+1;++i){
			if (prev == tempm[i]){
				mc[lasty].second++;
			}
			else{
				mc.push_back({tempm[i],1});
				lasty++;
			}
			prev = tempm[i];
		}	
		int ans = 0;
		lasty++;
		vector<int> pref(lasty+1,0);
		for (int i = 1;i<=lasty;++i){
			pref[i] += pref[i-1] + mc[i-1].second;
		}
		if ((k-n) % pref[lasty] == 0){
			int delta = (k - n) / pref[lasty];
			if (mc[0].first + delta >= 1){
				ans++;
			}
		}
		
		for (int i = 0;i<lasty-1;++i){
			n -= mc[i].first*mc[i].second;
			int rem = pref[lasty] - pref[i+1];
			if ((k-n) % (rem) == 0){
				int delta = (k-n)/rem;
				if (mc[i+1].first + delta >= 1){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}

