#include <iostream>
#include <vector>
using namespace std;

int main(){
    int q;
    cin >> q; 
    vector<vector<long long>> matrix = {
        {1,2,3,4,5,6,7,8,9,0,45},
        {2,4,6,8,0,20},
        {3,6,9,2,5,8,1,4,7,0,45},
        {4,8,2,6,0,20},
        {5,0,5},
        {6,2,8,4,0,20},
        {7,4,1,8,5,2,9,6,3,0,45},
        {8,6,4,2,0,20},
        {9,8,7,6,5,4,3,2,1,0,45}
    };
    while (q!=0){
        q--;
        long long n,m;
        cin >> n >> m;
        long long div = n/m;
        m = m%10;
        if (m == 0){
            cout << 0 << endl;
            continue;
        }
        long long ans = matrix[m-1][matrix[m-1].size()-1]*(div/(matrix[m-1].size() - 1));
        for (long long i = 0;i< div % (matrix[m-1].size()-1);i++){
            ans += matrix[m-1][i];
        }
        cout << ans << endl;

    }
}