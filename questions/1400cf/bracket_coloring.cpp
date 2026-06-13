#include <bits/stdc++.h>
using namespace std;

//1837 D. Bracket Coloring - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;
		vector<stack<char>> sts(2);
		bool curr = (s[0] == '(') ? 0 : 1;
		vector<int> colors;
		int numc = 1;
		for (char i : s){
			if (i - '(' == curr){
				sts[curr].push(i);
			}
			else if (sts[curr].empty()){
				curr ^= 1; sts[curr].push(i);
				numc = 2;
			}
			else{
				sts[curr].pop();
			}
			colors.push_back(curr+1);
		}
		if (sts[0].empty() && sts[1].empty()){
			cout << numc << '\n';
			for (int i = 0;i<n;++i)
				cout << min(numc,colors[i]) << " ";	
			cout << '\n';
		}
		else{
			cout << -1 << '\n';
		}
	}
}
