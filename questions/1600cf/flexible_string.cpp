#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		string a,b; cin >> a >> b;

		set<char> c;
		for (char i: a){
			c.insert(i);
		}

		int setsize = c.size();
		k = min((int)c.size(), k);

		int mask = (1 << setsize) - 1;

		long long totcount = 0;
		long long cnt = 0;

		vector<char> vc(c.begin(), c.end());

		while (true){
			if (__builtin_popcount(mask) == k){
				cnt = 0;
				long long last = 0;

				for (int i = 0; i < n; ++i){
					bool done = false;

					if (a[i] == b[i]){
						done = true;
					}
					else {
						for (int j = 0; j < setsize; ++j){
							if ((mask & (1 << j)) && vc[j] == a[i]){
								done = true;
								break;
							}
						}
					}

					if (done){
						last++;
					}
					else{
						cnt += last * (last + 1) / 2;
						last = 0;
					}
				}

				cnt += last * (last + 1) / 2;
			}

			totcount = max(totcount, cnt);

			if (mask == 0)
				break;

			mask--;
		}

		cout << totcount << '\n';
	}
}
