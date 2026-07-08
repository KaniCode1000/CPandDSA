#include <bits/stdc++.h>
using namespace std;

// A. - 2238 codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n,c; cin >> n >> c;
		vector<int> a(n),b(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
		}		
		for (int i = 0;i<n;++i){
			cin >> b[i];
		}		
		long long oldsteps = 0;
		long long mapped = 0;
		for (int i = 0;i<n;++i){
			if (a[i] < b[i]){
				mapped = 1;
				break;
			}	
			oldsteps += a[i] - b[i];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		long long steps = 0, ans = -1;
		bool done = false;
		for (int i = 0;i<n;++i){
			if (a[i] >= b[i]){
				steps += a[i]-b[i];
			}	
			else{
				done = true;
				break;
			}
		}
		if (done){
			cout << ans << '\n';
			continue;
		}
		if (oldsteps != steps)
			mapped = 1;
		ans = steps + mapped*c;
		cout << ans << '\n';
	}
}
