#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t!=0){
        t-=1;
        unordered_map<int,vector<int>> mp;
        int n;
        int val = 1;
        cin >> n;
        bool done = true;
        int a[n];
        for (int i = 0;i<n;i++){
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        for (auto key: mp){
            if (key.second.size() % key.first != 0){
                cout << -1 << endl;
                done = false;
                break;
            }
            else{
                for (int i = 0;i<key.second.size()/key.first;i++){
                    for (int j = 0;j<key.first;j++){
                        a[key.second[i*key.first + j]] = val;
                    }
                    val += 1;
                }
            }
        }
        if (done){
            for (int x: a){
                cout << x << ' ';
            }
            cout << endl;
        }
    }
}