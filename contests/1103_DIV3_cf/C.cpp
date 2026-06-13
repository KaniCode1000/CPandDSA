#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		long long a,b,x; cin >> a >> b >> x;
		auto maxymin = [&](){
			long long temp = min(a,b);
			a = max(a,b);
			b = temp;	
		};
		maxymin();
		long long ops = a - b;
		long long divops = 0;
		while (a != b){
			ops = min(ops,divops + (a - b));
			a /= x;
			maxymin();
			divops++;
		}
		ops = min(ops,divops);
		cout << ops << '\n';
	}	
}
