#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        int n;
        int o = 0;
        cin >> n;
        long long a[n];
        long long total = 0;
        for (int i = 0;i<n;i++){
            cin >> a[i];
            if (a[i]%2){
                o++;
            }
            else{
                total += a[i];
            }
        }
        if (o == 0){
            cout << 0 << endl;
        }
        else{
            sort(a,a+n);
            o = (o+1)/2;
            for (int i = n-1; i >=0;i--){
                if (a[i]%2){
                    o--;
                    total += a[i];
                }
                if (o == 0){
                    
                    break;
                }
            }   
            cout << total << endl;
        }

    }
}