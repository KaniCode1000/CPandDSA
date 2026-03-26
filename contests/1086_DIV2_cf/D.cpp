#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0;i<n;i++){
            cin >> a[i];
        }
        vector<pair<int,int>> edges;

        for (int i  = 0;i<n;i++){
            for (int j =0;j<n;j++){
                if (i == j || a[i][j] == '0'){
                    continue;
                }
                bool detour = false;
                for (int k = 0;k<n;k++){
                    if (i == k || j == k){
                        continue;
                    }
                    if (s[i][k] == '1' && s[k][j] == '1'){
                        detour = true;
                        break;
                    }
                }
                if (!detour){
                    edges.push_back({i+1,j+1});
                }
            }
        }

        if (edges.size() != n-1){
            cout << "No" << endl;
        }

        vector<vector<int>> adj_undir;
        vector<vector<int>> adj_dir;
        for (auto& edge : edges) {
            adj_undir[edge.first].push_back(edge.second);
            adj_undir[edge.second].push_back(edge.first);
            adj_dir[edge.first].push_back(edge.second);
        }

        vector<bool> visited(n+1,false);
        vector<int> q;
        int head = 0;
        q.push_back(1);
        while (head <= q.size()){
            int v = q[head];
            head++;
            for (auto& edge: adj_undir[v])
        }

    }
}