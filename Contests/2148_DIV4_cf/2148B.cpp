#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        long long x,y;
        int n,m;
        cin >> n >> m >> x >> y;
        long long a[n];
        long long b[m];
        long long total = 0;
        for (int i = 0;i<n;i++){
            cin >> a[i];
        }
        for (int i = 0;i<m;i++){
            cin >> b[i];
        }
        cout << n+m << endl;
    }
}