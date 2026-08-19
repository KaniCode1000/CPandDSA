#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
	if (n == 1){
		cout << 1 << '\n';
	}
	else if (n == 2){
		cout << -1 << '\n';
	}
	else{
		vector<long long> ans = {1,2,3};
		long long summ = 6;
		for (int i = 0;i<n-3;++i){
			ans.push_back(summ);
			summ += summ;
		}
		for (long long i: ans){
			cout << i << " ";
		}
		cout << '\n';
	}
    }
}
