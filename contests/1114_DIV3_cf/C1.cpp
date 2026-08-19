#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string a,b; cin >> a >> b;
		int o=0,e = 0;
		for (int i = 0;i<n;++i){
			if (i % 2){
				o = o + (a[i]-'0') - (b[i] - '0');
			}
			else{
				e = e + (a[i]-'0') - (b[i] - '0');
			}
		}
		if (o == 0 && e == 0){
			cout << "YES" << '\n';
		}
		else{
			cout << "NO" << '\n';
		}
	}
}
