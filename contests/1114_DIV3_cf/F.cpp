#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n),b(n);
		int axor = 0,bxor = 0;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			axor ^= a[i];
		}
		for (int i = 0;i<n;++i){
			cin >> b[i];
			bxor ^= b[i];
		}
		int findxor = axor ^ bxor;
		bool found = !findxor;
		for (int i = 0;i<n;++i){
			if (!found && a[i] == findxor){
				found = true;
			}	
			else{
				a[i] ^= findxor;
			}
		}
		if (!found){
			cout << "NO" << '\n';
			continue;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for (int i = 0;i<n;++i){
			if (a[i] != b[i]){
				cout << "NO" << '\n';
				found = false;
				break;
			}
		}
		if (found){
			cout << "YES" << '\n';
		}
		
	}
}
