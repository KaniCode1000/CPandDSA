#include <bits/stdc++.h>

using namespace std;

//1935 D codeforces

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		long long c;
		cin >> n >> c;
		vector<long long> s(n);
		long long ans = c+1 + ((c+1)*(c+1) - (c+1))/2; 
		long long odd = 0;
		long long even = 0;
		for (int i = 0;i<n;i++){
			cin >> s[i];
			ans -= c - s[i] + s[i]/2 + 1;				
			(s[i] % 2) ? even++ : odd++;
		}
		ans += (odd*(odd-1))/2 + (even*(even-1))/2;
		cout << ans << endl;
	}	
}
