#include <bits/stdc++.h>
using namespace std;

// Problem 3: Circular Barn - Usaco

vector<long long> dp_bfr, dp_cur,a,pref,prefi;

long long C(int l, int r){
	return (prefi[r+1] - prefi[l])-(pref[r+1] - pref[l])*1LL*(l+1);	
}

void compute(int l, int r,int optl, int optr){
	if (l > r)
		return;
	
	int mid = (l + r) >> 1;
	pair <long long,int> best = {LLONG_MAX,-1};
	
	for (int i = optl; i <= min(mid,optr);++i){
		best = min(best,{(i? dp_bfr[i-1]:(long long) 0) + C(i,mid),i});
	}
	
	dp_cur[mid] = best.first;
	int opt = best.second;

	compute(l,mid-1,optl,opt);
	compute(mid+1,r,opt,optr);
}

long long solve(int n,int k){
	for (int i = 0;i<n;++i){
		dp_bfr[i] = C(0,i);
	}	
	
	for (int i = 1; i<k;++i){
		compute(0,n-1,0,n-1);
		dp_bfr = dp_cur;
	}
	
	return dp_bfr[n-1];
}

int main(){
	freopen("cbarn.in","r",stdin);
	freopen("cbarn.out","w",stdout);
	int n,k; cin >> n >> k;
	vector<long long> arr(2*n);
	pref.assign(n+1,0);
	prefi.assign(n+1,0);
	a.assign(n,0);
	for (int i = 0;i<n;++i){
		cin >> arr[i];
		arr[i+n] = arr[i];
	}
	long long ans = LLONG_MAX;
	for (int i=0;i<n;++i){
		for (int j = 0;j<n;++j){
			a[j] = arr[j+i];
		}
		pref.assign(n+1,0);
		prefi.assign(n+1,0);
		dp_bfr.assign(n,0); dp_cur.assign(n,0);
		for (int i = 1;i<=n;++i){
			pref[i] = pref[i-1] + a[i-1];
			prefi[i] = prefi[i-1] + a[i-1]*i;
		}
		ans = min(ans,solve(n,k));
	}
	cout << ans << '\n';
	fclose(stdin); fclose(stdout);
}
