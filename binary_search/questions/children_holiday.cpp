#include <bits/stdc++.h>
using namespace std;

// D. Children Holiday - Step2 Edu Codeforces

signed main(){
	int m,n; cin >> m >> n;
	vector<int> t(n),z(n),y(n);
	for (int i = 0;i<n;++i){
		cin >> t[i] >> z[i] >> y[i];
	}
	int low = 0, high = 1e7;
	int ans = 0;
	while (low <= high){
		int mid = low + (high-low)/2;
		long long balloons = 0;
		for (int i = 0;i<n;++i){
			long long breakt = z[i]*t[i] + y[i];
			balloons += (mid/breakt)*z[i] + min((long long) z[i],(mid%breakt)/t[i]);
		}
		if (balloons >= m){
			ans = mid;
			high = mid-1;	
		}
		else{
			low = mid+1;
		}
	}
	vector<int> bcnt(n);
	cout << ans << '\n';
	for (int i = 0;i<n;++i){
		bcnt[i] = min(m, (ans/(z[i]*t[i] + y[i]))*z[i] + min( z[i],(ans%(z[i]*t[i] + y[i]))/t[i]));
		m = max(0, m - bcnt[i]);
		cout << bcnt[i] << " ";
	}
	cout << '\n';
}
