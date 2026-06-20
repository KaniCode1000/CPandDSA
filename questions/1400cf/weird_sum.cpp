#include <bits/stdc++.h>
using namespace std;

// 1648 A. Weird Sum - Codeforces

int main(){
	int n,m; cin >> n >> m;
	vector<vector<int>> rows(100000),cols(100000);
	set<int> colors;
	for (int i = 0;i<n;++i){
		for (int j = 0;j<m;++j){
			int x; cin >> x;
			rows[x-1].push_back(i);
			cols[x-1].push_back(j);
			colors.insert(x-1);
		}
	}
	long long count = 0;
	for (int i: colors){
		long long rowpref = 0,colpref = 0;
		sort(rows[i].begin(),rows[i].end());
		sort(cols[i].begin(),cols[i].end());
		for (int x = 0;x<rows[i].size();++x){
			count += (1LL*x)*rows[i][x] - rowpref;
			rowpref += rows[i][x];	
		}
		for (int x = 0;x<cols[i].size();++x){
			count += (1LL*x)*cols[i][x] - colpref;
			colpref += cols[i][x];	
		}	
	}
	cout << count << '\n';
	
}
