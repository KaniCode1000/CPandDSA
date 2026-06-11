#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,x,y,z;
		cin >> n >> x >> y >> z;
		if (n - x*z <= 0){
			cout << (n+ x + y -1)/(x+y) << '\n';
		}
		else{
			cout << min((n+x+y-1)/(x+y), z + ((n-(x*z) + x + 10*y - 1)/(x+ 10*y))) << '\n';
		}
	}
}
