#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    char matrix[n][m];
    queue<pair<int,int>> q;
    pair<int,int> A;
    for (int i = 0;i < n;i++){
        string row;
        cin >> row;
        for (int j = 0; j < m; j++){
            matrix[i][j] = row[j];
        }
    }
    for (int i = 0;i<n;i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == '.' && (i == 0 || i == n-1 || j == 0 || j == m-1)){
                matrix[i][j] = 'W';
            }
            else if (matrix[i][j] == 'M'){
                q.push({i,j});
            }
            else if (matrix[i][j] == 'A'){
                A = {i,j};
            }
        }
    }
    q.push(A);

    pair<int,int> answer = {-1,-1};
    while (!q.empty()){
        pair<int,int> v = q.front();
        q.pop();
        int i = v.first;
        int j = v.second;
        if (matrix[i][j] == 'M'){
            if (i > 0 && (matrix[i-1][j] == '.' || matrix[i-1][j] == 'W')){
                matrix[i-1][j] = 'M';
                q.push({i-1,j});
            }
            if (j > 0 && (matrix[i][j-1] == '.' || matrix[i][j-1] == 'W')){
                matrix[i][j-1] = 'M';
                q.push({i,j-1});
            }
            if (i < n-1 && (matrix[i+1][j] == '.' || matrix[i+1][j] == 'W')){
                matrix[i+1][j] = 'M';
                q.push({i+1,j});
            }
            if (j < m-1 && (matrix[i][j+1] == '.' || matrix[i][j+1] == 'W')){
                matrix[i][j+1] = 'M';
                q.push({i,j+1});
            }
        }
        else{
            if (i > 0 && (matrix[i-1][j] == '.' || matrix[i-1][j] == 'W')){
                q.push({i-1,j});
                if (matrix[i-1][j] == 'W'){
                    answer = {i-1,j};
                    matrix[i-1][j] = 'D';
                    break;
                }
                matrix[i-1][j] = 'D';
            }
            if (i < n-1 && (matrix[i+1][j] == '.' || matrix[i+1][j] == 'W')){
                q.push({i+1,j});
                if (matrix[i+1][j] == 'W'){
                    answer = {i+1,j};
                    matrix[i+1][j] = 'U';
                    break;
                }
                matrix[i+1][j] = 'U';
            }
            if (j > 0 && (matrix[i][j-1] == '.' || matrix[i][j-1] == 'W')){
                q.push({i,j-1});
                if (matrix[i][j-1] == 'W'){
                    answer = {i,j-1};
                    matrix[i][j-1] = 'R';
                    break;
                }
                matrix[i][j-1] = 'R';
            }
            if (j < m-1 && (matrix[i][j+1] == '.' || matrix[i][j+1] == 'W')){
                q.push({i,j+1});
                if (matrix[i][j+1] == 'W'){
                    answer = {i,j+1};
                    matrix[i][j+1] = 'L';
                    break;
                }
                matrix[i][j+1] = 'L';
            }
        }
    }
    if (A.first == 0 || A.first == n-1 || A.second == 0 || A.second == m-1){
        cout << "YES" << endl;
        cout << 0 << endl;
        cout << endl;
    }
    else if  (answer.first == -1 && answer.second == -1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        vector<char> path;
        int i = answer.first;
        int j = answer.second;
        while (matrix[i][j] != 'A'){
            if (matrix[i][j] == 'L'){
                j--;
                path.push_back('R');
            }
            else if (matrix[i][j] == 'R'){
                j++;
                path.push_back('L');
            }
            else if (matrix[i][j] == 'U'){
                i--;
                path.push_back('D');
            }
            else {
                i++;
                path.push_back('U');
            }
        }
        reverse(path.begin(),path.end());
        cout << path.size() << endl;
        for (char i: path){
            cout << i;
        }
        cout << endl;
    }

}