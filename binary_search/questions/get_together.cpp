#include <bits/stdc++.h>
using namespace std;

// A. Get Together - Step3 Edu Codeforces

int main(){
	int n; cin >> n;
	vector<double> x(n),v(n);
	for (int i = 0;i<n;++i){
		cin >> x[i] >> v[i];
	}
	double ans = 1e10;
	double l = 0, h = 1e10;
	for (int i = 0; i < 100;++i){
		double m = l + (h-l)/2; 
		double lower = x[0] - v[0]*m, upper = x[0] + v[0]*m;
		for (int i = 1;i<n;++i){
			lower = max(x[i] - v[i]*m,lower);
			upper = min(upper,x[i] + v[i]*m);
		}
		if (upper >= lower){
			ans = m;
			h = m;
		}
		else
			l = m;
	}
	cout << setprecision(20) << ans << '\n';
}
