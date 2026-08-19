#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
		
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		int total = 0;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			total += a[i];
		}
		cout << ((total%4 == 0)?("YES"):("NO")) << '\n';
		
	}
}
