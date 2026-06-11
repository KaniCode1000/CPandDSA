#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		long long n,x1,x2,k;
		cin >> n >> x1 >> x2 >> k;
		long long dist = min(abs(x1-x2),n - abs(x1-x2));
		if (n == 2 || n == 3){
			cout << 1 << '\n';
		}
		else{
			cout << dist+k << '\n';
		}
		
	}
}
