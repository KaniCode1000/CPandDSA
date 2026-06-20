#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		long long n,x,y; cin >> n >> x >> y;
		vector<long long> a(n);
		bool parity = x&1;
		for (long long i = 0;i<n;++i){
			cin >> a[i];
			parity ^= (a[i]&1);
		}
		if (parity == (bool) (y&1))
			cout << "Alice" << '\n';
		else{
			cout << "Bob" << '\n';
		}
	}

}
