#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        long long sumkm2,sumk1,sumkm1;
        sumkm2 = sumkm1 = sumk1 = 0;
        long long n,k;
        cin >> n >> k;
        long long low = n+1;
        long long a[n];
        long long c[n+1];
        for (int i = 0;i<n;i++){
            cin >> a[i];
            c[i] = 0;
        }
        c[n] = 0;
        for (int i =0;i<n;i++){
            c[a[i]] += 1;
        }
        for (int i = 0;i<n+1;i++){
            if (c[i] == 0){
                low = i;
                break;
            } 
        }
        // cout << low << endl;
        for (int i = 0;i<n;i++){
            if (c[a[i]] > 1 || a[i] > low || c[a[i]] == 0){
                sumk1 += low;
                c[a[i]] = 0;
                a[i] = low;
                c[low] += 1;
            }
            else{
                sumk1 += a[i];
            }
        }

        if (k == 1){
            cout << sumk1 << endl;
            continue;
        }
        low = n+1;
        for (int i = 0;i<n+1;i++){
            if (c[i] == 0){
                low = i;
                break;
            } 
        }
        for (int i = 0;i<n;i++){
            if (c[a[i]] > 1 || a[i] > low || c[a[i]] == 0){
                sumkm2 += low;
                c[a[i]] = 0;
                a[i] = low;
                c[low] += 1;
            }
            else{
                sumkm2 += a[i];
            }
        }
        if (k%2 == 0){
            cout << sumkm2 << endl;
            continue;
        }
        low = n+1;
        for (int i = 0;i<n+1;i++){
            if (c[i] == 0){
                low = i;
                break;
            } 
        }
        for (int i = 0;i<n;i++){
            if (c[a[i]] > 1 || a[i] > low || c[a[i]] == 0){
                sumkm1 += low;
                c[a[i]] = 0;
                a[i] = low;
                c[low] += 1;
            }
            else{
                sumkm1 += a[i];
            }
        }
        if (k%2 == 1){
            cout << sumkm1 << endl;
            continue;
        }

    }
}