#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n,k,m; cin >> n >> k >> m;
		if (k >= m+1){
			cout <<"NO" << '\n';
			continue;
		}	
		else{
			cout << "YES" << '\n';
			for (int i = 0;i<n-1;++i){
				cout << 1 << " ";
			}
			cout << m-k+1 << '\n';
		}
	}	
}
