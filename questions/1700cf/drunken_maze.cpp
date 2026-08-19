#include <bits/stdc++.h>
using namespace std;

//D. Drunken Maze - Codeforces

vector<int> dr = {-1,1,0,0}, dc = {0,0,-1,1};

struct state_data{
	int r,c,d,cnt;
};

void solve(){
	int n,m; cin >> n >> m;
	vector<string> adj(n);
	pair<int,int> st,end;
	for (int i = 0;i<n;++i){
		cin >> adj[i];
		for (int j = 0;j<m;++j){
			if (adj[i][j] == 'S'){
				st = {i,j};
			} else if (adj[i][j] == 'T'){
				end = {i,j};
			}
		}
	}
	vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(m,vector<vector<int>>(4,vector<int>(4,-1))));
	int ans = -1;
	queue<state_data> q;
	for (int i = 0;i<4;++i){
		int nr = st.first + dr[i];
		int nc = st.second + dc[i];

		if (nr >= 0 && nr <= n-1 && nc >= 0 && nc <= m-1 && adj[nr][nc] != '#'){
			dist[nr][nc][i][1] = 1;
			q.push({nr,nc,i,1});
		}
	}
	
	while (!q.empty()){
		state_data top = q.front();
		q.pop();

		if (adj[top.r][top.c] == 'T'){
			ans = dist[top.r][top.c][top.d][top.cnt];
			break;
		}
		
		for (int d = 0;d<4;++d){
			int r = top.r + dr[d];
			int c = top.c + dc[d];
		
			if (r >= 0 && c >= 0 && r <= n-1 && c <= m-1 && adj[r][c] != '#'){
				int nxt_cnt = (d == top.d) ? (top.cnt + 1):(1);
				if (nxt_cnt > 3){
					continue;
				}
				if (dist[r][c][d][nxt_cnt] == -1){
					dist[r][c][d][nxt_cnt] = dist[top.r][top.c][top.d][top.cnt] +1;
					q.push({r,c,d,nxt_cnt});
				}
			}
		}
	}
	cout << ans << '\n';
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
