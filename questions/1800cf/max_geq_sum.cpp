#include <bits/stdc++.h>

using namespace std;

//1691D. Max Geq Sum - Codeforces

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--){
		int n;cin >> n;
		vector<long long> a(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
		}
		
		vector<long long> pref(n,0);
		pref[0] = a[0];
		for (int i = 1;i<n;++i){
			pref[i] = pref[i-1] + a[i];
		}
		auto rsum = [&](int L,int R){
			if (L == 0)
				return pref[R];
			return pref[R] - pref[L-1];
		};
		vector<int> posies;
		for (int i = 0;i<n;++i){
			if (a[i] > 0) posies.push_back(i);
		}
		
		bool done = true;
		stack<int> stk,rstk;
		for (int index: posies){
			while(!stk.empty() && a[stk.top()] < a[index])
				stk.pop();

			if (!stk.empty()){
				int l = stk.top(),r = index;
				if (max(a[r],a[l]) < rsum(l,r)){
					done = false; 
					break;
				}
			}
			stk.push(index);
		}

		if (done){
			for (int i = (int) posies.size()-1;i>=0;--i){
				int index = posies[i];
				while (!rstk.empty() && a[rstk.top()] < a[index])
					rstk.pop();
				if (!rstk.empty()){
					int l = index,r = rstk.top();
					if (max(a[r],a[l]) < rsum(l,r)){
						done = false;
						break;
					}
				}
				rstk.push(index);
			}
		}
		cout << (done? "YES": "NO") << '\n';
	}
}
