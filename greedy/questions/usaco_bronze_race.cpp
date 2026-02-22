#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double k,n;
    cin >> k >> n;
    while (n!=0){
        n--;
        double x;
        cin >> x;
        if (k <= x*(x-1)/2){
            cout << ceil((sqrt(1+8*k)-1)/2) << endl;
        }
        else if(k <= x*(x+1)/2){
            cout << x << endl;
        }
        else{
            cout << ceil(-x + 2*sqrt(x*x -x + k - x*(x-1)/2)) << endl;
        }
    }
}