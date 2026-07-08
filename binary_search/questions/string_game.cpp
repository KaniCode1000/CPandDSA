#include <bits/stdc++.h>
using namespace std;

//F. String Game - Step2 Edu Codeforces

int main(){
	string t,p; cin >> t >> p;
	int ts = t.size(),ps = p.size();
	vector<int> a(ts);
	for (int i = 0;i<ts;++i){
		cin >> a[i];
	}
	int l = 0,h = ts;
	auto good = [&](int m) -> bool{
		vector<char> word(ts);
		for (int i = 0;i<ts;++i){
			word[i] = t[i];
		}
		for (int i = 0;i<m;++i){
			word[a[i]-1] = 'A';
		}
		int j = 0;
		for (int i= 0;i<ts;++i){
			if (word[i] == p[j])
				++j;
			if (j == ps)
				break;
		}
		if (ps == j){
			return true; 
		}
		return false;
	};
	int ans = 0;
	while (l <= h){
		int m = l + (h-l)/2;
		if (good(m)){
			l = m+1;
			ans = m;
		}
		else{
			h = m-1;
		}
	}
	cout << ans << '\n'; 

}
