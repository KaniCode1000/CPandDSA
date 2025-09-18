#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        int n,k;
        cin >> n >> k;
        int a[n];
        bool done = false;
        int b[n];
        int c[n]; 
        for (int i = 0;i<n;i++){
            cin >> a[i];
            b[i] = 0;
            c[i] = 0;
        }
        for (int i = 0;i<n;i++){
            b[a[i]-1] += 1;
        }
        for (int i = 0;i<n;i++){
            if (b[i] % k == 0){
                b[i] /= k;
            }
            else{
                done = true;
                break;
            }
        }
        if (done){
            cout << 0 << endl;
        }
        else{
            long long num = 0;
            int low = 0;
            for (int i = 0;i<n;i++){
                c[a[i] -1] += 1;

                while (c[a[i] - 1] > b[a[i] - 1] && low < n){
                    c[a[low] - 1] -= 1;
                    low++;
                }
                num += i-low+1;
            }
            cout << num << endl;
        }

    }
}