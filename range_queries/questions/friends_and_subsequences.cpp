#include <bits/stdc++.h>

using namespace std;

int log2_floor(long long i){
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main(){
	int n; cin >> n;
	
	vector<long long> a(n),b(n);
	int K = log2_floor(n);
	vector<vector<long long>> sta(K+1, vector<long long>(n,0));
	vector<vector<long long>> stb(K+1, vector<long long>(n,0));
	
	for (int i = 0;i<n;++i){
		cin >> a[i]; sta[0][i] = a[i];}
				
	for (int i = 0;i<n;++i){
		cin >> b[i]; stb[0][i] = b[i];}
	
	for (int i = 1; i <= K;++i){
		for (int j = 0; j + (1 << i) <= n; ++j){
			sta[i][j] = max(sta[i-1][j],sta[i-1][j + (1 << (i-1))]);
			stb[i][j] = min(stb[i-1][j],stb[i-1][j + (1 << (i-1))]);
		}
	}
	
	auto amax = [&](int i,int j){
		int value = log2_floor(1LL * (j-i+1));
		return max(sta[value][i],sta[value][j- (1 << value)+1]);
	};
	auto bmin = [&](int i,int j){
		int value = log2_floor(1LL * (j-i+1));
		return min(stb[value][i],stb[value][j- (1 << value)+1]);
	};
	
	auto bsl = [&](int l,int left){
		int first_match = -1;
		int r = n-1,mid,f;
		while (l <= r){
			mid = l + (r-l)/2;
			f = amax(left,mid) - bmin(left,mid);
			if (f == 0){
				first_match = mid;
				r = mid-1;
			}
			else if(f > 0){
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		return first_match;
	};
	
	auto bsr = [&](int l,int left){
		int first_match = -1;
		int r = n-1,mid,f;
		while (l <= r){
			mid = l + (r-l)/2;
			f = amax(left,mid) - bmin(left,mid);
			if (f == 0){
				first_match = mid;
				l = mid+1;
			}
			else if(f > 0){
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		return first_match;
	};
	long long ans = 0,L,R;
	for (int i = 0;i<n;++i){
		L = bsl(i,i);
		R = bsr(i,i);
		if (L == -1){
			continue;
		}
		int val = R-L+1;
		ans += val;
	}
	cout << ans << '\n';
}
