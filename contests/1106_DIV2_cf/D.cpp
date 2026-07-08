#include <bits/stdc++.h>
using namespace std;

// D. - 2238 codeforces

//returns vector of lowest prime factors array
vector<int> linear_sieve(int n){
	vector<int> lp(n+1,0);
	vector<int> pr;

	for (int i = 2;i<=n;i++){	
		if (lp[i] == 0){
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i*pr[j] <= n; ++j){
			lp[i*pr[j]] = pr[j];
			if (pr[j] == lp[i]){
				break;
			}
		}
	}
	return lp;
}

//returns factorisation of a number
map<int,int> pfac(int n,const vector<int> &lp){
	map<int,int> uniquefacs;
	int last_fac = -1;
	while (n>1){
		if (lp[n] == last_fac){
			uniquefacs[lp[n]]++;
		}
		else{
			uniquefacs.insert({lp[n],1});	
			last_fac = lp[n];
		}
		n /= lp[n];
	}
	return uniquefacs;
}

int main(){
	int t; cin >> t;
	vector<int> lp = linear_sieve(1e6);
	while (t--){
		int n; cin >> n;
		map<int,int> primefacs = pfac(n,lp);	
		long long ans = -1;
		for (pair<int,int> i: primefacs){
			ans += i.second + 1;	
		}
		cout << ans << '\n';
	}
}
