#include <bits/stdc++.h>

using namespace std;

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
set<int> pfac(int n,const vector<int> &lp){
	set<int> uniquefacs;
	while (n>1){
		uniquefacs.insert(lp[n]);
		n /= lp[n];
	}
	return uniquefacs;
}

int main(){

}
