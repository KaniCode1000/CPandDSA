#include <bits/stdc++.h>
using namespace std;

//B Edu 189 - Codeforces

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		string ss; cin >> ss;
		vector<bool> s;
		for (char i: ss){
			s.push_back(i-'a');
		}
		int n = s.size();
		int l = -1;
		for (int i = 1;i<n;++i){
			if (s[i] == s[i-1]){
				l = i;
				break;
			}	
		}
		if (l == -1 || l == n-1){
			cout << "YES" << '\n';
			continue;
		}
		int r = -1;
		for (int i = l+1;i<n;++i){
			if (s[i-1] == s[i]){
				r = i;
				break;
			}
		}
		if (r== -1 || r == n-1){
			cout << "YES" << '\n';
			continue;
		}
		int break3 = false;
		for (int i = 1+r;i<n;++i){
			if (s[i] == s[i-1]){
				break3 = true;
				break;
			}
		}
		cout << (break3?"NO":"YES") << '\n';
	}
}
