#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t!=0){
        t--;
        int n,q;
        cin >> n >> q;
        char x[n];
        bool same = true;
        for (int i = 0;i<n;i++){
            cin >> x[i];
            if (x[i] == 'B'){
                same = false;
            }
        }
        long long a[q];
        for (int i =0;i<q;i++){
            cin >> a[i];
            if (same){
                cout << a[i] << endl;
            }
            else{
                int z = 0;
                int time = 0;
                while (a[i] != 0){
                    if (x[z] == 'A'){
                        a[i] -= 1;
                    }
                    else{
                        a[i] /= 2;
                    }
                    z++;
                    time ++;
                    z %= n;
                }
                cout << time << endl;
            }
        }

    }
}