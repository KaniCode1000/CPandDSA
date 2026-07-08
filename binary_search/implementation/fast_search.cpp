#include <bits/stdc++.h>
using namespace std;

//Question: How many numbers between l and r (if elements are equal to l or r, count all of them)

int main(){
	int n; cin >> n;
	vector<long long> a(n);
	for (long long &x: a) cin >> x;
	int k; cin >> k;
	sort(a.begin(),a.end());
	while (k--){
		long long l,r; cin >> l >> r;
		auto low = lower_bound(a.begin(),a.end(),l),high = upper_bound(a.begin(),a.end(),r);
		cout << high-low << ' ';
	}
	cout << endl;
}
