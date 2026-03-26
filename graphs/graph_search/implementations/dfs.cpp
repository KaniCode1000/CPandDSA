/*
This is the most simple implementation of Depth First Search. As described in the applications 
it might be useful to also compute the entry and exit times and vertex color. We will color all vertices with the color 0,
if we haven't visited them, with the color 1 if we visited them, and with the color 2, if we already exited the vertex.
*/
// n - number of vertices, adj - graph as adjacency list
vector<vector<int>> adj;
int n; 

vector<int> color;

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}