#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t!=0){
        t--;
        int n;
        cin >> n;
        long long arr[n];
        long long meow[n];
        for (int i = 0;i<n;i++){
            cin >> arr[i];
            meow[i] = arr[i];
        }
        sort(meow,meow+n);
        long long lowest,highest;
        lowest = meow[0];
        highest = meow[n-1];
        long long maxdiff = meow[n-1];
        bool done = true;
        for (int i =0;i<n;i++){
            if (meow[i] == arr[i]){
                continue;
            }
            else{
                maxdiff = min(maxdiff,max(abs(meow[i]-highest),abs(meow[i] - lowest)));
                done = false;
            }
        }
        if (done){
            cout << -1 << endl;
        }
        else{
            cout << maxdiff << endl;
        }
    }
}