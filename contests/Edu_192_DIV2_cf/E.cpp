#include <bits/stdc++.h>
using namespace std;

//Edu 192 E - Codeforces

int log2_floor(long long i){
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void binstring(vector<int> &rep,long long v){
	while (v > 0){
		rep.push_back(v & 1);
		v >>= 1;
	}
	reverse(rep.begin(),rep.end());
	return;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		long long l,r,n; cin >> l >> r >> n;
		long long k = log2_floor(r);
		long long high_pow = (1ll << k);
		long long x,y;
		if (l <= (high_pow >> 1ll)){
			x = (high_pow >> 1ll);
			y = high_pow; 
		}	
		else if (l <= high_pow){
			x = l;
			y = high_pow;
		}
		else{
			int val = 30;
		 	x = l;
			while (((r >> val) & 1) == ((l >> val) & 1)){
				val--;
			}
			y = l + (1ll << val) - (l & ((1ll << val) - 1ll)); 
		}

		vector<int> xrep,yrep;
		binstring(xrep,x);
		binstring(yrep,y);
		int xsiz = xrep.size(),ysiz = yrep.size();
		string ans(n,'0');
		for (int i = 0;i<n;++i){
			ans[i] = '0' + ((xrep[i % xsiz]) & (yrep[i % ysiz]));
		}
		cout << ans << '\n';
	}
}

