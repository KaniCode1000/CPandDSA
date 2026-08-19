#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int m,n; cin >> n >> m;
		vector<pair<int,int>> segs;
		for (int i = 0;i<m;++i){
			pair<int,int> lr = {0,0};
			cin >> lr.first >> lr.second;
			lr.first--; lr.second--;
			segs.push_back(lr);
		}
		vector<int> a(n,1e6),p(n+1,0);
		int q; cin >> q;
		for (int i = 0;i<q;++i){
			int temp; cin >> temp;
			a[temp-1] = i;
		}
		int low = 0,high=q-1;
		int ans = -2;
		while (low <= high){
			int mid = low + (high-low)/2;
			for (int i = 1;i<=n;++i){
				p[i] = p[i-1] + (a[i-1] <= mid);
			}
			bool done = false;
			for (int i = 0;i<m;++i){
				if (segs[i].second - segs[i].first + 1 < 2*(p[segs[i].second+1]-p[segs[i].first])){
					done = true;
					break;
				}	
			}
			if (done){
				high = mid-1;
				ans = mid;
			}
			else{
				low = mid+1;
			}
		}
		cout << ans+1 << '\n';
	}
}
