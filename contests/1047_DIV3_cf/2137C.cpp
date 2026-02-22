#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        long long a,b;
        cin >> a >> b;
        if (a%2 == 0){
            if (b%2 == 1){
                cout << -1 << endl;
            }
            else{
                cout << ((a*(b/2))+2) << endl;
            }
        }
        else{
            if (b%2 == 1){
                cout << (a*b + 1) << endl;
            }
            else if (b%4 != 0){
                cout << -1 << endl;
            }
            else{
                cout << (a*(b/2) + 2) << endl;
            }
        }
    }
}