#include <bits/stdc++.h>

using namespace std;

//1732 C1 Codeforces

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n,q;
		cin >> n >> q;
		vector<long long> a(n);
		vector<long long> ps(n), px(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
		}
		ps[0] = px[0] = a[0];
		for (int i = 1;i<n;++i){
			ps[i] = a[i] + ps[i-1];
			px[i] = a[i] ^ px[i-1];
		}
		int L,R;
		cin >> L >> R;
		long long maxval = ps[n-1] - px[n-1];
		int maxr = n-1;
		int maxl = 0;
		if (maxval == 0){
			cout << 1 << " " << 1 << endl;
			continue;
		}
		for (int r = 1; r < n;++r){
			int low = 0;
			int high = r;
			int mid = low + (high-low)/2;
			while (low <= high){
				long long sumval,xorval;
				int mid = low + (high-low)/2;
				if (mid == 0){
					sumval = ps[r];
					xorval = px[r];
				}
				else{
					sumval = ps[r]-ps[mid-1];
					xorval = px[r]^px[mid-1];
				}
				if (sumval - xorval != maxval && r-mid + 1 >= maxr-maxl+1){
					break;
				}
				else if (sumval - xorval == maxval){
					if (r-mid+1 < maxr - maxl + 1){
						maxr = r;
						maxl = mid;
					}
					low = mid+1;
				}
				else {
					high = mid-1;
				}
			}
		}
		cout << maxl + 1 << " " << maxr + 1 << endl;
		
	}
}
