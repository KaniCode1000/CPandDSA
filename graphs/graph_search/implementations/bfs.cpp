#include <bits/stdc++.h>
using namespace std;

void bfs(int &n, int &s, int &u, vector<vector<int>> &adj) {
    queue<int> q;
    vector<bool> used(n, false);
    vector<int> d(n, 0), p(n, -1);

    q.push(s);
    used[s] = true;
    p[s] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : adj[v]) {
            if (!used[w]) {
                used[w] = true;
                q.push(w);
                d[w] = d[v] + 1;
                p[w] = v;
            }
        }
    }

    // Display shortest path from s to u
    if (!used[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}

int main(){

}

