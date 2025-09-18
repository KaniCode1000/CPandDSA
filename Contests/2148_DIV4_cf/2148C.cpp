#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        int n;
        long long m;
        cin >> n >> m;
        long long a[n];
        int b[n];
        int bit = 0;
        long long total = m;
        for (int i = 0;i<n;i++){
            cin >> a[i];
            cin >> b[i];
            if ((a[i]+bit)%2 != b[i]){
                total--;
                bit^=1; 
            }
        }
        cout << total << endl;
    }
}