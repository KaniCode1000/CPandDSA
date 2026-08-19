#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;
		map<char,int> freq;
		for (char c: s){
			freq[c]++;
		}
		int ans = n,bi = 1;
		vector<pair<int,char>> best;
		for (char c = 'a';c<='z';c++){
			best.push_back({freq[c],c});	
		}
		sort(best.begin(),best.end());
		for (int i = 1;i<=26;++i){
			if (n % i){
				continue;
			}
			int tempans = n;
			int f = n/i;
			for (int j = 0; j < i; ++j) {
				tempans -= min(best[25-j].first, f);
			}
			if (tempans < ans){
				ans = tempans;
				bi = i;
			}				
		}
		int f = n/bi;
		set<char> x;
		for (int j = 0;j<bi;++j){
			x.insert(best[best.size()-1-j].second);
		}
		map<char,int> more;
		for (char i:x){
			more[i] = f;
		}
		
		string anst = s;
		for (int i = 0;i<n;++i){
			char c = s[i];
			if (x.count(c) && more[c] > 0){
				more[c]--;
				anst[i] = c;
			} else{
				anst[i] = 'A';
			}
		}
		
		for (int i = 0;i<n;++i){
			if (anst[i] != 'A'){
				continue;
			}
					
			for (auto [c,cnt]: more){
				if (cnt > 0){
					anst[i] = c;
					more[c]--;
					break;
				}
			}
		}
		cout << ans << '\n';
		cout << anst << '\n';
		
	}
}	
