#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n,k,d;
	cin >> n >> k >> d;
	int count = n-1;
	vector<vector<pair<int,int>>> arr(n);
	int val,val2;
	bool ans[n];
	bool explored[n];
	queue<int> q;
	int police_node;
	for (int i =0;i<n;i++){
		ans[i] = true;
		explored[i] = false;
	}
	for (int i = 0;i<k;i++){
		cin >> police_node;
		q.push(police_node);
		explored[police_node-1] = true;
	}
	for (int i = 0;i<n-1;i++){
		cin >> val >> val2;
		arr[val-1].push_back({val2,i+1});
		arr[val2-1].push_back({val,i+1});
	}
	while (!q.empty()){
		int node_rem = q.front();
		q.pop();
		for (int i = 0;i < arr[node_rem-1].size();i++){
			if (explored[arr[node_rem-1][i].first -1]==false){
				explored[arr[node_rem-1][i].first - 1] = true;
				ans[arr[node_rem-1][i].second-1] = false;
				count--;
				q.push(arr[node_rem-1][i].first);	
			}
		}
	}
	cout << count << endl;
	for (int i = 0;i<n-1;i++){
		if (ans[i] == true){
			cout << i+1 << " ";
		}
	}

}
