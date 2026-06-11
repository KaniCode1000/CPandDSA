#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> pref(n);
		int val = s[0]-'(';
		pref[0] = (val^1) - val;
		for (int i = 1;i<n;++i){
			pref[i] = pref[i-1] + ((s[i] - '(')^1) - (s[i]-'(');	
		}
		pair<int,int> mini = {0,0};
		for (int i = 0;i<n;++i){
			if (pref[i] < mini.first){
				mini = {pref[i],i+1};
			}
		}
		vector<int> indices;
		for (int i = 0;i<mini.second;++i){
			if (s[i] - '(' == 0){
				indices.push_back(i);
			}
		}
		for (int i = mini.second;i<n;++i){
			if (s[i] - ')' == 0){
				indices.push_back(i);
			}
		}
		
		int delnum = min(k,(int) indices.size());
		string ans = "";
		for (int i = 0;i<n;++i){
			ans += '0';
		}
		for (int i = 0;i<indices.size();++i){
			if (delnum == 0){
				break;
			}
			ans[indices[i]] = '1';
			delnum--; 
		}
		cout << ans << '\n';
	}
}
