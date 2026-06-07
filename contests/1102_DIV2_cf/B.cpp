#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		long long a,b;
		a = n%12;
		if (a == 10){
			a = 22;
		}
		if (a > n){
			cout << -1 << '\n';
			continue;	
		}
		b = n-a;
		cout << a << " " << b << '\n';
	}	
}

