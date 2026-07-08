#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//190E. Ciel and Gondolas - Codeforces
int n,k;
vector<vector<int>> prefu;
vector<long long> dp_bfr,dp_cur;

long long C(int l, int r){
	return (prefu[r+1][r+1] + prefu[l][l] - prefu[r+1][l] - prefu[l][r+1])/2;
}

void compute(int l,int r,int optl,int optr){
	if (l > r)
		return;
	int mid = (l) + (r-l)/2;
	
	pair<long long,int> best = {LLONG_MAX,-1};
	for (int i = optl;i<= min(mid,optr);++i){
		best = min(best,{(i?dp_bfr[i-1]:0) + C(i,mid),i});
	}
	
	int opt = best.second;
	dp_cur[mid] = best.first;
	
	compute(l,mid-1,optl,opt);
	compute(mid+1,r,opt,optr);
	
}

long long solve(){
	dp_bfr.assign(n,0), dp_cur.assign(n,0);
	
	for (int i = 0;i<n;++i){
		dp_bfr[i] = C(0,i);
	}

	for (int i = 1;i<k;++i){
		compute(0,n-1,0,n-1);
		dp_bfr = dp_cur;
	}

	return dp_bfr[n-1];
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	char temp;	
	prefu.assign(n+1,vector<int>(n+1,0));
	for (int i = 0;i<n;++i){
		for (int j = 0;j<n;++j){
			cin >> temp;
			prefu[i+1][j+1] = prefu[i][j+1] + prefu[i+1][j] - prefu[i][j] + (temp - '0');
		}
	}
	cout << solve() << '\n';
	
}
