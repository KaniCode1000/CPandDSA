#include <bits/stdc++.h>
using namespace std;

// A. Guards - https://codeforces.com/gym/103536/problem/A

vector<long long> pref;

//follows the Quadrangial inequality (NEEDS TO BE IMPLEMENTED BASED ON THE QUESTION)
long long C(int i, int j, vector<long long> &arr){
	long long val = pref[j];
	if (i != 0){
		val -= pref[i-1];
	}
	return val * (j-i+1);
}

//for dp(i,j) = min 0 <= k <= j - dp(i-1,k-1) + C(k,j) where i - number of partitions and j is position in array and C(k,j) is the cost of putting elements from k...j in one group

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr, vector<long long> &dp_before, vector<long long> &dp_cur,vector<long long> &arr) {
	if (l > r)
		return;

	int mid = (l + r) >> 1;
	pair<long long, int> best = {LLONG_MAX, -1};

	for (int k = optl; k <= min(mid, optr); k++) {
		best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid,arr), k});
	}

	dp_cur[mid] = best.first;
	int opt = best.second;

	compute(l, mid - 1, optl, opt,dp_before,dp_cur,arr);
	compute(mid + 1, r, opt, optr,dp_before,dp_cur,arr);
}

long long solve(int n,int m,vector<long long> &dp_before, vector<long long> &dp_cur,vector<long long> &arr){
	dp_before.assign(n,0);
	dp_cur.assign(n,0);

	for (int i = 0; i < n; i++)
		dp_before[i] = C(0, i,arr);

	for (int i = 1; i < m; i++) {
		compute(0, n - 1, 0, n - 1,dp_before,dp_cur,arr);
		dp_before = dp_cur;
	}

	return dp_before[n - 1];
}


int main(){
	// n - length of array, m - number of segments
	int m,n; cin >> n >> m;
	pref.assign(n,0);
	vector<long long> arr(n);
	for (long long &x: arr) cin >> x;
	pref[0] = arr[0];
	for (int i = 1;i<n;++i){
		pref[i] = pref[i-1]+arr[i];
	}
	vector<long long> dp_before,dp_cur;
	cout << solve(n,m,dp_before,dp_cur,arr) << '\n';
}


