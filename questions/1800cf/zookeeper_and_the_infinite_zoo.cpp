#include <bits/stdc++.h>

using namespace std;

// 1491 D. Zookeeper and The Infinite Zoo - Codeforces

int main(){
	int q;
	cin >> q;
	while (q--){
		long long u,v;
		cin >> u >> v;
		int cnt = 0;
		if (u > v){
			cout << "NO\n";
			continue;
		}
		bool done = true;
		while (v!=0 || u != 0){
			cnt += u&1;
			cnt -= v&1;
			u/=2;
			v/=2;
			if (cnt < 0){
				done = false;
				break;
			}
		}
		cout << ((done)? "YES\n":"NO\n");
	}
}
