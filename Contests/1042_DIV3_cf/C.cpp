#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    for (int m = 0;m<t;m++){
        int n;
        map<int,int> umap;
        int k;
        bool done = true;
        cin >> n;
        cin >> k;
        int S[n];
        int T[n];
        for (int i = 0;i<n;i++){
            cin >> S[i];
            umap[S[i]%k] += 1;
            umap[k - (S[i]%k)] += 1;
        }
        for (int i = 0;i<n;i++){
            cin >> T[i];
            umap[T[i]%k] -= 1;
            umap[k - (T[i]%k)] -= 1;
        }
    for (auto i:umap){
        if (i.second < 0){
            cout << "NO" << endl;
            done = false;
            break;
        }
    }
    if (done){
        cout << "YES" << endl;
    }

    }
}