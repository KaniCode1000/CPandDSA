#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string a,b; cin >> a >> b;
		vector<int> ao,ae,bo,be;
		int o = 0,e = 0;
		for (int i = 0;i<n;++i){
			if (i%2){
				o += (a[i] - '0') - (b[i] - '0');
				if (a[i] == '1')
					ao.push_back(i/2);
				if (b[i] == '1')
					bo.push_back(i/2);
			}
			else{
				e += (a[i] - '0') - (b[i] - '0');
				if (a[i] == '1')
					ae.push_back(i/2);
				if (b[i] == '1')
					be.push_back(i/2);
			}
		}
		if (o != 0 || e != 0){
			cout << -1 << '\n';
			continue;
		}
		long long ans = 0;
		for (int i = 0;i<ao.size();++i){
			ans += abs(ao[i] - bo[i]);
		}
		for (int i = 0;i<ae.size();++i){
			ans += abs(ae[i]-be[i]);
		}	
		cout << ans << '\n';
	}
}
