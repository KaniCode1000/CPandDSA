#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> p(n);
		vector<int> component(n);
		vector<char> visited(n,false);
		for (int i = 0;i<n;++i){
			cin >> p[i];
		}
		int numcycles = 0;
		int sub = -1;
		for (int i = 0;i<n;i++){
			if (visited[i] == true){
				continue;
			}
			component[i] = ++numcycles;
			visited[i] = true;
			int nexty = p[i] - 1;
			while (visited[nexty] == false){
				visited[nexty] = true;
				component[nexty] = numcycles;
				nexty = p[nexty] - 1;
			}
		}
		for (int i = 1;i<n;i++){
			if (component[i] == component[i-1]){
				sub = 1;
				break;
			}
		}
		cout << n - sub - numcycles << endl;
	}
}
