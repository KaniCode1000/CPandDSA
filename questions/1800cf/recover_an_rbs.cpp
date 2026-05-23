#include <bits/stdc++.h>

using namespace std;

//C. Recover an RBS Codeforces

int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n;
		n = s.size();
		int oc = 0;
		int qc = 0;
		for (int i = 0;i<n;++i){
			if (s[i] == '?'){
				qc++;
			}
			else if (s[i] == '(')
				oc++;
		}
		int on = n/2 - oc;
		int index = -1;
		int ind2 = -1;
		for (int i = 0;i<n;++i){
			if (s[i] == '?'){
				if (on > 0){
					s[i] = '(';
					on--;
					index = i;
				}
				else {
					s[i] = ')';
					if (ind2 == -1){
						ind2 = i;
					}
				}
			}
		}
		if (ind2 == -1 || index == -1){
			cout << "YES" << endl;
			continue;
		}
		swap(s[ind2],s[index]);
		int value = 0;
		bool done = true;
		for (char c: s){
			if (c == '('){
				value++;
			}
			else if (value != 0){
				value--;
			}
			else{
				done = false;
				break;
			}
		}
		if (value != 0){
			done = false;	
		}
		string ans = (done) ? "NO" : "YES";
		cout << ans << endl;
	}
}
