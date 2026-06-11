#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		int ntyp = 0;
		map<long long,vector<int>> poses;
		vector<pair<int,int>> cands;
		for (int i = 0;i<n;++i){
			cin >> a[i];
			if (poses[a[i]].empty()){
				ntyp++;
			}
			if (!poses[a[i]].empty() && poses[a[i]].back() + 1 != i){
				cands.push_back({poses[a[i]].back(),i});
			} 
			poses[a[i]].push_back(i);
		}
		if (cands.size() == 0){
			cout << "YES" << '\n';
			continue;
		}
		else if (cands.size() > 4){
			cout << "NO" << '\n';
			continue;
		}
		bool done =false;
		set<int> totcands;
		for (pair<int,int> i: cands){
			totcands.insert(i.second);	
			totcands.insert(i.second-1);	
			totcands.insert(i.first+1);	
			totcands.insert(i.first);	
			totcands.insert(poses[a[i.first]].front());
			totcands.insert(max(poses[a[i.first]].front()-1,0));
			totcands.insert(max(poses[a[i.second]].front()-1,0));
			totcands.insert(poses[a[i.second]].front());
			totcands.insert(poses[a[i.first]].back());
			totcands.insert(min(n-1,poses[a[i.first]].back()+1));
			totcands.insert(min(n-1,poses[a[i.second]].back()+1));
			totcands.insert(poses[a[i.second]].back());
		}
		auto check= [&]() -> bool {
			int tran = 0;
			for (int i = 1;i<n;++i){
				if (a[i] != a[i-1])
					tran++;	
			}
			if (tran+1 == ntyp){
				return true;
			}
			return false;
		};
		for (int y: totcands){
			if (done)
				break;
			for (int j: totcands){
				if (done)
					break;
				if (y>=j)
					continue;
				swap(a[y],a[j]);
				done = check();
				swap(a[y],a[j]);
			}
		}
		if (done){
			cout << "YES" << '\n';
		}
		else if (!done){
			cout << "NO" << '\n';
		}

	}
}
