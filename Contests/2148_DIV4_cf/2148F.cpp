#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        int n,k;
        int maxk = 0;
        cin >> n;
        int m = 200000;
        int val = 0;
        bool done = false;
        bool notmaxk = false;
        int a[m];
        while(n){
            n--;
            cin >> k;
            for (int i = 0;i<k;i++){
                cin >> val;
                if (done == true){
                    a[i] = val;
                }
                else if ((i < maxk) && a[i] < val){
                    notmaxk = true;
                }  
                else if (i  >= maxk || maxk == 0 || (notmaxk == false && a[i] > val)){
                    a[i] = val;
                    done = true;
                }
            }
            done = false;
            notmaxk = false;
            maxk = max(k,maxk);
        }       
        for (int i = 0;i<maxk;i++){
            cout << a[i] << " ";
        } 
        cout << endl;
    }
}