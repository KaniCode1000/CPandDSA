#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<int> sieve(int n) {
    
    // creation of boolean array
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            // marking as false
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

int main() { 
    int t;
    int nnnnn = 200000;
    cin >> t;
    vector<int> res = sieve(nnnnn);
    while (t!=0){
        t--;
        ll n;
        cin >> n;
        pair<ll,ll> arr[n];
        ll mincost = 2;
        ll maxe = 0;
        ll maxe2 = 0;
        for (int i = 0;i<n;i++){
            cin >> arr[i].first;
            if (maxe <= arr[i].first){
                maxe2 = maxe;
                maxe = arr[i].first;
            }
            else if (maxe2 < arr[i].first){
                maxe2 = arr[i].first;
            }
        }
        for (int i = 0;i<n;i++){
            cin >> arr[i].second;
            // mincost += arr[i].second;
        }
        if (maxe == maxe2 && maxe2 > 1){
            cout << 0 << endl;
            continue;
        }
        else if (maxe2 == 1){
            cout << ((maxe%2)?2:1) << endl;
            continue;
        }
        for (int p = 0;p<res.size();p++){
            if (mincost == 0 || res[p] > maxe2){
                break;
            }
            int cnt0 = 0;
            int cntn_1 = 0;
            for (int i = 0;i<n;i++){
                if (arr[i].first%res[p] == 0){
                    cnt0++;
                }
                else if (arr[i].first%res[p] == res[p]-1){
                    cntn_1++;
                }
                if (cnt0 == 2){
                    mincost = 0;
                    break;
                }
            }
            if (cnt0 == 1 && cntn_1 >= 1){
                mincost = 1;
            }
        }
        cout << mincost << endl;
    }
    cout << res.size() << endl;
}