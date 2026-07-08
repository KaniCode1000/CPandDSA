#include <bits/stdc++.h>
using namespace std;

//Edu 192 D - Codeforces

int lis(vector<pair<int,int>> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i].second) - d.begin();
        if (d[l-1] < a[i].second && a[i].second < d[l])
            d[l] = a[i].second;
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		string a,b; cin >> a >> b;
		int asiz = a.size(),bsiz = b.size();
		vector<pair<int,int>> op;
		vector<int> pa(asiz),pb(bsiz);
		pa[0] = a[0] - '0';
		pb[0] = b[0] - '0';
		for (int i = 1;i<asiz;++i){
			pa[i] = pa[i-1] + (a[i]-'0');
			pa[i] %= 10;
		}
		for (int i = 1;i<bsiz;++i){
			pb[i] = pb[i-1] + (b[i] - '0');
			pb[i] %= 10;
		}
		if (pa[asiz-1] != pb[bsiz-1]){
			cout << -1 << '\n';
			continue;
		}
		for (int i = 0;i<asiz;++i){
			for (int j = bsiz-1;j>=0;--j){
				if (pa[i] == pb[j]){
					op.push_back({i,j});
				}	
			}
		}
		int ans = lis(op);
		cout << (ans?ans:-1) << '\n';
	}
}

