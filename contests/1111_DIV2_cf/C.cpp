#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n),b(n);
		int m1=0,m0 = 0,i1 = 0,i0 = 0;
		for (int i = 0;i<n;++i){
			cin >> a[i];	
		}
		for (int i = 0;i<n;++i){
			cin >> b[i];
			if (a[i] == b[i]){
				if (a[i] == 0){
					i0 += 1;
				}
				else{
					i1++;
				}
			}
			else{
				if (a[i] == 0){
					m0++;
				}
				else{
					m1++;
				}
			}
		}	
		if (m1%2 == 1){
			cout << 1 << '\n';
		}
		else if (m1 == 0){
			if (m0 == 0){
				cout << 0 << '\n';
			}
			else if (i1 == 0){
				cout << -1 << '\n';
			}
			else{
				if (i0 == 0){
					cout << -1 << '\n';
				}	
				else{
					cout << 2 << '\n';
				}
			}
		}
		else{
			cout << 2 << '\n';
		}
		
	}	
	
}
