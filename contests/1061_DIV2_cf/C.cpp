#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t!=0){
        t--;
        int n,k;
        cin >> n >> k;
        int a[n];
        for (int i = 0;i<n;i++){
            cin >> a[i];
        }
        sort(a,a+n);
        int maxgcd = a[k];
        if (k == n-1){
            cout << maxgcd << endl;
            continue;
        }
        bool done = false;
        while (maxgcd != 1 && !done){
            int dels = 0;
            done = true;
            for (int i = 0;i<n;i++){
                if (a[i]%maxgcd != 0 && (a[i] != 3*maxgcd && a[i] < 4*maxgcd)){
                    dels++;
                    if (dels > k){
                        done = false;
                        maxgcd--;
                        break;
                    }
                }
            }
        }
        cout << maxgcd << endl;
    }
}