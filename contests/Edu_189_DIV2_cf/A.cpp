#include <bits/stdc++.h>
using namespace std;

//A Edu 189 - Codeforces

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		long long x,y; cin >> x >> y;
		long long z = ((y/x)-1)*x;
		cout << (z == x? "NO" : "YES") << '\n';
	}
}
