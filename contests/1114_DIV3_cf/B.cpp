#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;
		string newstr = "";
		newstr += s[0];
		int siz1 = 0;
		for (int i = 1;i<n;++i){
			if (s[i] != s[i-1]){
				newstr += s[i];
			}
			if (siz1 != 2 && i < n-1 && s[i] != s[i+1] && s[i] != s[i-1]){
				if (s[i-1] == s[i+1]){
					siz1 = 2;
				}
				else{
					siz1 = 1;
				}
			}
		}
		cout << newstr.size() - siz1 << '\n';
	}
}
