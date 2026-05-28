#include <bits/stdc++.h>

using namespace std;

// 1335 E2. Three Blocks Palindrome - Codeforces

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<vector<int>> indices(200);
		vector<int> asize(200,0);
		vector<int> a(n,0);
		vector<vector<int>> p(n,vector<int>(200,0));
		for (int i = 0;i<n;++i){
			cin >> a[i];
			indices[a[i]-1].push_back(i);	
			asize[a[i]-1] += 1;
			p[i][a[i]-1] = 1;
		}
		for (int i = 1;i<n;++i){
			for (int ai = 0;ai<200;ai++){
				p[i][ai] += p[i-1][ai];	
			}
		}
		int ans = *max_element(asize.begin(),asize.end());
		for (int ai = 0;ai<200;++ai){
			if (asize[ai] == 0)
				continue;
			int cnt,l,r;
			for (int k = 1; k <= asize[ai]/2; ++k){
				l = indices[ai][k-1];
				r = indices[ai][asize[ai]-k];
				for (int b = 0;b < 200;++b){
					cnt = max(0,p[r-1][b] - p[l][b]);
					ans = max(ans,2*k + cnt);
				}
			}
		}
		cout << ans << endl;
	}
}
