#include <iostream>
#include <deque>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0;i<n;i++) cin >> a[i];

    deque<int> maxdq,mindq; //mindq - monotone increasing maxdq-  montone decreasing
    int low = 0;
    long long ans = 0;
    for (int r = 0;r < n;r++){
        while (!maxdq.empty() && a[maxdq.back()] <= a[r]) maxdq.pop_back();
        maxdq.push_back(r);

        while (!mindq.empty() && a[mindq.back()] >= a[r]) mindq.pop_back();
        mindq.push_back(r);

        while (!mindq.empty() && !maxdq.empty() && a[maxdq.front()] - a[mindq.front()] > k){
            low++;
            if (maxdq.front() < low) maxdq.pop_front();
            if (mindq.front() < low) mindq.pop_front();
        }
    ans += r-low+1;
    }
    cout << ans << endl;
}