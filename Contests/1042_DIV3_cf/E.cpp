#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int m =0;m<t;m++){
        int n;
        bool done = true;
        cin >> n;
        int a[n];
        int b[n];
        int c[n];
        for (int i = 0;i<n;i++){
            cin >> a[i];
        }
        for (int i = 0;i<n;i++){
            cin >> b[i];
        }
        if (a[n-1] != b[n-1]){
            cout << "NO" << endl;
            done = false;
        }
        c[n-1] = b[n-1];
        if (done)
        {
            for (int i = n-2;i >= 0; i--)
            {
                int y = a[i]^a[i+1];
                int x = a[i]^c[i+1];
                if (a[i] == b[i]){
                    c[i] = b[i];
                }
                else if (y == b[i]){
                    c[i] = y;
                }
                else if (x == b[i]){
                    c[i] = x;
                }
                else{
                    cout << "NO" << endl;
                    done = false;
                    break;
                }
            }
        }

        if (done){
            cout << "YES" << endl;
        }   
    }
}