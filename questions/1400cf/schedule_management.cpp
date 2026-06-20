#include <bits/stdc++.h>
using namespace std;

//1701 C. Schedule Management - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n,m; cin >> n >> m;
		vector<int> a(m);
		for (int &x: a) cin >> x, --x;
		vector<int> cnt(n,0);
		int low = 1;
		int high = 2 * ((m+n-1)/n);
		int mid;
		for (int i = 0;i<m;++i){
			cnt[a[i]]++;
		}
		int leasttime = 2*m;
		while (low <= high){
			mid = low + (high-low)/2;
			int extra = 0, rqd = 0;
			for (int x: cnt){
				extra += max(0,mid-x)/2;
				rqd += max(0,x-mid);
			}
			if (extra < rqd){
				low = mid +1;
			}		
			else{
				high = mid-1;
				leasttime = mid;
			}
		}
		cout << leasttime << '\n';
	}
}
