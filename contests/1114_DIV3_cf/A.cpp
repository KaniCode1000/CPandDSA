#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int a,b,c; cin >> a >> b >> c;
		int maxy = max(a,max(b,c));
		int mini = min(a,min(b,c));
		int mid = a+b+c - maxy - mini;
		cout << min(maxy-mid,mid-mini) << '\n';
	}
}
