#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> b(n);
		for (int i = 0;i<n;++i){
			cin >> b[i];
		}
		sort(b.begin(),b.end(),greater<int>());
		bool done = true;
		for (int i = 2;i<n;++i){
			if (b[i-2]%b[i-1] != b[i]){
				done = false;
				break;
			}
		}
		if (done){
			for (int i=0;i<2;++i){
				cout << b[i] << " ";
			}
		}
		else{
			cout << -1;
		}
		cout << '\n';
	}	
}
