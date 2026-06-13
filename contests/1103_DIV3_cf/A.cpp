#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> h(n);
		for (int i = 0;i<n;++i){
			cin >> h[i];
		}
		int mini = h[0],maxy = h[0];
		for (int i = 0;i<n;++i){
			mini = min(h[i],mini);
			maxy = max(h[i],maxy);
		}
		cout << maxy + 1 - mini << '\n';
	}	
}
