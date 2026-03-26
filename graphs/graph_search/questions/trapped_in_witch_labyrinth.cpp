#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(pair<int,int> v, vector<vector<pair<char,int>>> &matrix, int n, int m) {
    // If we hit a cycle (1), a known trap (3), or a '?' (which can always trap incoming paths), 
    // this path is trapped.
    if (matrix[v.first][v.second].second == 1 || 
        matrix[v.first][v.second].second == 3 || 
        matrix[v.first][v.second].first == '?'){
        matrix[v.first][v.second].second = 3;
        return;
    }
    
    // If we hit a known escape route
    if (matrix[v.first][v.second].second == 2){
        return;
    }
    
    // Mark as visiting to detect cycles
    matrix[v.first][v.second].second = 1;
    
    // Check if we step off the board
    if (matrix[v.first][v.second].first == 'R' && v.second == m-1){
        matrix[v.first][v.second].second = 2;
        return;
    }
    if (matrix[v.first][v.second].first == 'L' && v.second == 0){
        matrix[v.first][v.second].second = 2;
        return;
    }
    if (matrix[v.first][v.second].first == 'U' && v.first == 0){
        matrix[v.first][v.second].second = 2;
        return;
    }
    if (matrix[v.first][v.second].first == 'D' && v.first == n-1){
        matrix[v.first][v.second].second = 2;
        return;
    }
    
    // Move to the next cell
    pair<int,int> cell;
    if (matrix[v.first][v.second].first == 'D') cell = {v.first+1, v.second};
    else if (matrix[v.first][v.second].first == 'U') cell = {v.first-1, v.second};
    else if (matrix[v.first][v.second].first == 'R') cell = {v.first, v.second+1};
    else if (matrix[v.first][v.second].first == 'L') cell = {v.first, v.second-1};
    
    dfs(cell, matrix, n, m);
    
    // Inherit the state from where we landed
    matrix[v.first][v.second].second = matrix[cell.first][cell.second].second;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    // matrix[i][j].first = char, matrix[i][j].second = state (0, 1, 2, 3)
    vector<vector<pair<char,int>>> matrix(n, vector<pair<char,int>>(m));
    
    for (int i = 0; i < n; i++){
        string row;
        cin >> row;
        for (int j = 0; j < m; j++){
            matrix[i][j].first = row[j];
            matrix[i][j].second = 0;
        }
    }
    
    vector<pair<int,int>> unmapped;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            pair<int,int> v = {i, j};
            
            if (matrix[v.first][v.second].first == '?'){
                if (v.first > 0 && (matrix[v.first-1][v.second].first == 'D' || matrix[v.first-1][v.second].first == '?')){
                    matrix[v.first-1][v.second].second = 3;
                    matrix[v.first][v.second].second = 3;
                }
                if (v.second > 0 && (matrix[v.first][v.second-1].first == 'R' || matrix[v.first][v.second-1].first == '?')){
                    matrix[v.first][v.second-1].second = 3;
                    matrix[v.first][v.second].second = 3;
                }
                if (v.first < n-1 && (matrix[v.first+1][v.second].first == 'U' || matrix[v.first+1][v.second].first == '?')){
                    matrix[v.first+1][v.second].second = 3;
                    matrix[v.first][v.second].second = 3;
                }
                if (v.second < m-1 && (matrix[v.first][v.second+1].first == 'L' || matrix[v.first][v.second+1].first == '?')){
                    matrix[v.first][v.second+1].second = 3;
                    matrix[v.first][v.second].second = 3;
                }
                
                if (matrix[v.first][v.second].second == 0){
                    unmapped.push_back(v);
                }
                continue;
            }
            
            // Run DFS on normal cells if unvisited
            if (matrix[v.first][v.second].second == 0){
                dfs(v, matrix, n, m);
            }
        }
    }
    
    // Process the unmapped '?' cells based on fully resolved DFS neighbors
    for (pair<int,int> v: unmapped){
        if (v.first > 0 && matrix[v.first-1][v.second].second == 3){
            matrix[v.first][v.second].second = 3;             
        }
        else if (v.first < n-1 && matrix[v.first+1][v.second].second == 3){
            matrix[v.first][v.second].second = 3;             
        }
        else if (v.second > 0 && matrix[v.first][v.second-1].second == 3){
            matrix[v.first][v.second].second = 3;             
        }
        else if (v.second < m-1 && matrix[v.first][v.second+1].second == 3){
            matrix[v.first][v.second].second = 3;             
        }
        else {
            matrix[v.first][v.second].second = 2;
        }
    }

    // Tally up the final score
    int trapped_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j].second == 3) {
                trapped_count++;
            }
        }
    }
    cout << trapped_count << "\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}