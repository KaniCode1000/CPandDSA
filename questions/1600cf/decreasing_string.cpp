#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		long long pos; cin >> pos;
		stack<char> sk;
		long long value = s.size(),n=s.size();
		int final = -1;
		if (pos == 1){
			cout << s[0];
			continue;
		}
		while (pos > 0){
			pos -= value--;	
			final++;
		}
		int deletions = 0;
		sk.push(s[0]);
		int index = 1;
		while (index != n){
			while (!sk.empty() && s[index] < sk.top() && deletions != final){
				deletions++;
				sk.pop();
			}
			sk.push(s[index]);
			index++;
		}
		while (deletions != final){
			sk.pop();
			deletions++;
		}
		string ans = "";
		while (!sk.empty()){
			ans += sk.top();
			sk.pop();
		}
		reverse(ans.begin(),ans.end());
		cout << ans[pos+value];
	}
	cout << endl;
}
