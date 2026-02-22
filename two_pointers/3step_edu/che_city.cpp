#include <iostream>
using namespace std; 

int main(){
    long long n,r;
    cin >> n >> r;
    long long a[n];
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    long long low = 0;
    long long ans = 0;
    for (long long i = 1;i<n;i++){
        ans += low;
        while (a[i] - a[low] > r){
            low++;
            ans += 1;
        }
    }
    cout << ans << endl;
}