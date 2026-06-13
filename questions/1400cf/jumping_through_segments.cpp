#include <bits/stdc++.h>

using namespace std;

//1907 D. Jumping Through Segments

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<long long> l(n),r(n);
		long long maxy = 0;
		for (int i = 0;i<n;++i){
			cin >> l[i] >> r[i];
			maxy = max(r[i],maxy);
		}
		long long low = l[0];
		long long high = maxy;
		auto check = [&](long long step) -> bool {
			long long minstep = 0,maxstep = 0;	
			for (int i = 0;i<n;++i){
				minstep = max(minstep-step,l[i]);
				maxstep = min(maxstep+step,r[i]);
				if (minstep > r[i] || maxstep < l[i]){
					return false;
				}
			}
			return true;
		};
		long long mid;
		long long ans = 0;
		while (low <= high){
			mid = low + (high - low)/2;
			if (check(mid)){
				high = mid-1;
				ans = mid;
			}
			else{
				low = mid+1;
			}
		}
		cout << ans << '\n';
		
		
	}
}
