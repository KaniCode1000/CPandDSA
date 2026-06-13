#include <bits/stdc++.h>
using namespace std;

// 1919 C. Grouping Increases - Codeforces

int main(){
	int t; cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0;i<n;++i){
			cin >> a[i];
		}
		vector<int> b1, b2;
		b1.push_back(a[0]);
		int ans = 0;
		for (int i = 1;i<n;++i){
			if (b1.back() < a[i]){
				if (b2.empty()){
					b2.push_back(a[i]);
				}
				else if(b2.back() < a[i] && b1.back() < b2.back()){
					b1.push_back(a[i]);
					ans++;
				}
				else{
					if (b2.back() < a[i]){
						ans++;
					}
					b2.push_back(a[i]);
				}
			}
			else{
				if (!b2.empty() && b2.back() >= a[i] && b2.back() < b1.back()){
					b2.push_back(a[i]);
				}
				else{
					b1.push_back(a[i]);
				}
			}
		}
		cout << ans << '\n';
	}
}
