#include <bits/stdc++.h>

using namespace std;

//1396 B. Stoned Game - Codeforces

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> a(n);
		long long summ = 0;
		int maxy = 0;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			summ += a[i];
			maxy = max(a[i],maxy);
		}
		int parity = !(summ&1);
		summ -= maxy;
		if (maxy <= summ && parity){
			cout << "HL" << endl;
		}
		else{
			cout << "T" << endl;
		}
	}
}
