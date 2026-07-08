#include <bits/stdc++.h>
using namespace std;

//Edu 192 A - Codeforces

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<long long> c(n);
		for (int i = 0;i<n;++i){
			cin >> c[i];
		}
		sort(c.begin(),c.end(),greater<long long>());
		bool done = false;
		if (c[0] >= 3){
			done = true;
		}
		else if(n > 1 && c[0] >= 2 && c[1] >= 2){
			done = true;
		}
		cout << (done?"YES":"NO") << '\n';
	}
}
