#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n;
    long long s;
    cin >> n >> s;
    pair<long long,long long> a[n];
    for (int i =0;i<n;i++){
        a[i] = {(long long) (i), (long long) (i)};
        cin >> a[i].first;
    }

    for (int i =0;i<n;i++){
        cin >> a[i].second;
    }
    int low = 0;
    long long maxcost = 0;
    long long cost = 0;
    long long weights = 0;
    for (int r = 0;r < n;r++){
        weights += a[r].first;
        cost += a[r].second;
        while (weights > s){
            weights -= a[low].first;
            cost -= a[low].second;
            low++;
        }
        maxcost = max(cost,maxcost);
    }
    cout << maxcost << endl;
}