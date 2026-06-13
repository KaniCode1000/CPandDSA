#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		string s;
		cin >> s;
		int cnt = 0;
		bool done = true;
		for (int i = 0;i<k;++i){
			int j = i;
			while (j < n){
				cnt += s[j]-'0';
				j += k;
			}
			if (cnt % 2 == 1){
				done = false;
				break;
			}
		}
		if (!done){
			cout << "NO" << '\n';
		}
		else{
			cout << "YES" << '\n';
		}
	}
	
}
