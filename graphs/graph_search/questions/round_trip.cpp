#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int,int> explored;
unordered_map<int,int> parent;

int last_vertex = -1;
int first_vertex = -1;

void dfs(unordered_map<int,vector<int>> &adj, int vertex, int current_parent){
  if (last_vertex != -1) return; 

  explored[vertex] = 1;

  for (auto i: adj[vertex]){
    if (i == current_parent) continue; 

    if (explored[i] == 0){
      parent[i] = vertex;
      dfs(adj, i, vertex);
    }
    else if (explored[i] == 1 && last_vertex == -1){

      last_vertex = vertex;
      first_vertex = i;
      return;
    }
  }

  explored[vertex] = 2;
}

int main() {
  int n,m;
  cin >> n >> m;

  unordered_map<int,vector<int>> adj;

  int a,b;
  for (int i = 0;i<m;i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0;i<=n;i++){
    explored[i] = 0;
  }

  for (int i = 1; i <= n; i++){
    if (explored[i] == 0){
      dfs(adj,i,-1);
    }
  }

  if (last_vertex == -1){
    cout << "IMPOSSIBLE\n";
  }
  else{
    vector<int> cycle;
    cycle.push_back(first_vertex);

    int cur = last_vertex;
    while (cur != first_vertex){
      cycle.push_back(cur);
      cur = parent[cur];
    }

    cycle.push_back(first_vertex);

    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (auto x : cycle){
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}