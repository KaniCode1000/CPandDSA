#include <bits/stdc++.h>
using namespace std;

// C. Cows in Stalls - Step3 Edu Codeforces

int main(){
	int n,k; cin >> n >> k;
	vector<long long> a(n);
	for (long long &x: a) cin >> x;

	long long low = 1, high = 1e9, ans = 1;
	while (low <= high){
		long long mid = low + (high - low)/2;
		int cnt = 1, prev = 0;
		for (int i = 1;i<n;++i){
			if (a[i] - a[prev] >= mid){
				cnt++;	
				prev = i;
			}
		}
		if (cnt >= k){
			low = mid+1;
			ans = mid;
		}
		else{
			high = mid-1;
		}
	}
	cout << ans << '\n';
}
