#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        unordered_map<int,int> um;
        vector<int> a;
        int temp;
        for(int i = 0;i<n;i++){
            um[i+1] = 0;
        }
        for (int i = 0;i < n;i++){
            cin >> temp;
            a.push_back(temp);
        }
        vector<int> b;
        int count = 0;
        bool yes = true;
        for (int i = 0;i<n;i++){
            cin >> temp;
            b.push_back(temp);
            if (i <= n-k-1 || i >= k){
                if (temp != a[i] && temp != -1){
                    yes = false;
                }
            }
            else{
                if (temp != -1){
                    um[temp] -= 1;
                }
                else{
                    count++;
                }
                um[a[i]] += 1;
            }
        }
        for (auto i: um){
            if (i.second != 0){
                count--;
            }
        }
        if (count != 0){
            yes = false;
        }
        if (yes){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}