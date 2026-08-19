#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
	for (int i = 0;i<n;++i){
		cout << ((i+1)&1?i+2:i) << " ";
	}
	cout << '\n';
    }
}
