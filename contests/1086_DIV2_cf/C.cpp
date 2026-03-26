#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> c(n);
        vector<double> r(n);
        for (int i = 0;i<n;i++){
            cin >> c[i];
            cin >> r[i];
            r[i] = r[i]/100;
        }
        double meow = 0;

        for (int i = n-1;i>=0;i--){
            meow = max(meow, c[i] + (1.0 - r[i])*meow);
        }

        cout << fixed << setprecision(9) << meow << endl;
    }
}