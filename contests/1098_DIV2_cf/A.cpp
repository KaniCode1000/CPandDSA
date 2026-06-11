#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> w(n);
		vector<int> cnt(3,0);
		for (int i = 0;i < n;++i){
			cin >> w[i];
			cnt[w[i]]++;
		}
		cout << cnt[0] + min(cnt[1],cnt[2]) + (max(cnt[1],cnt[2])-min(cnt[1],cnt[2]))/3 << '\n';
	}	
}
