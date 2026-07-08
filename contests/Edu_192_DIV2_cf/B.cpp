#include <bits/stdc++.h>
using namespace std;

//Edu 192 B - Codeforces

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n,0),p1(n+1,0),p2(n+1,0);
		for (int i = 0;i<n;++i){
			cin >> a[i];
			p1[i+1] = p1[i] + (a[i]==1? 1 : -1);
			p2[i+1] = p2[i] + (a[i]<=2? 1 : -1);
		}
		int minimum = INT_MAX;
		bool done = false;
		for (int i = 2;i<n;++i){
			if (p1[i-1] >= 0){
				minimum = min(minimum,p2[i-1]);
			}
			
			if (minimum <= p2[i]){
				done = true;
				break;
			}
		}
		
		cout << (done? "YES":"NO") << '\n';
		
	}
}

