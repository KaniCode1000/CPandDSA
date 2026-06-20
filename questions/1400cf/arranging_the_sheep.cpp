#include <bits/stdc++.h>
using namespace std;

//1520 E. Arranging the Sheep - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;
		vector<tuple<int,int,int>> p;
		int l = 0,r = 0;
		for (int i = 0;i<n;++i){
			if (s[i] == '*')
				r++;
		}
		r--;
		for (int i = 0;i<n;++i){
			if (s[i] == '*'){
				p.push_back({l++,i,r--});	
			}	
		}
		if (p.size() < 2){
			cout << 0 << '\n';
			continue;
		}
		long long size = 0;
		pair<long long,int> minsize;
		for (int i = 1;i<p.size();++i){
			size += get<1>(p[i]) - get<1>(p[0]);	
		}
		minsize = {size,0};
		
		for (int i = 1;i<p.size();++i){
			size += (get<0>(p[i])-get<2>(p[i])-1)*(get<1>(p[i]) - get<1>(p[i-1]));	
			if (minsize.first > size){
				minsize = {size,i};
			}
		}
		l = get<0>(p[minsize.second]), r = get<2>(p[minsize.second]);
		cout << minsize.first -  ((long long) l)*((long long) (l+1))/2 - ((long long) r)*((long long) (r+1))/2 << '\n'; 
	}
}
