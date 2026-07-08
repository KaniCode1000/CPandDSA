#include <bits/stdc++.h>
using namespace std;

// G. Student Councils - Step2 Edu Codeforces

int main(){
	int k; cin >> k;
	int n; cin >> n;
	vector<long long> a(n);
	long long summ = 0;
	for (long long &x: a) cin >> x, summ += x;
	long long ans = 0, low = 0,high = summ;
	while (low <= high){
		long long m = low + (high-low)/2;
		long long count = 0;
		for (long long &x: a) count += min(x,m);
		if (count >= m*k){
			ans = m;
			low = m+1;
		}
		else{
			high = m-1;
		}
	}
	cout << ans << '\n';
}
