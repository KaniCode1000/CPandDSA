#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	vector<long long> a(n);
	long long summ = 0;
	for (long long &x: a) cin >> x, summ += x;
	double low = 0, high = *max_element(a.begin(),a.end());
	for (int i = 0;i<100;++i){
		double mid = low + (high-low)/2;
		long long tot = 0;
		for (long long val: a){
			tot += floor(val/mid);
		}		
		if (tot >= k){
			low = mid;
		}
		else{
			high = mid;
		}
	} 
	cout << setprecision(20) << low << '\n';
}
