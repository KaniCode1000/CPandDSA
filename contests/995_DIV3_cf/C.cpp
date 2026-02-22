#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int sss = 0;sss<t;sss++){
        int n;
        int m;
        int k;
        cin >> n;
        cin >> m;
        cin >> k;
        int arr[m];
        int q[k];
        for (int i = 0;i<m;i++){
            cin >> arr[i];
        }
        for (int i = 0;i<k;i++){
            cin >> q[i];
        }
        string ans = "";
        if (n-1 > k){
            for (int i = 0;i<m;i++){
                ans += '0';
            }
        }
        else if (n==k){
            for (int i = 0;i<m;i++){
                    ans += '1';
                } 
        }
        else{
            int val;
            bool done = true;
            for (int i = 1;i<n-1;i++){
                if (q[i]-q[i-1] > 1){
                    val = q[i]-1;
                    done = false;
                    break;
                }
            }
            if (done){
                if (q[n-2] == n){
                    val = 1;
                }
                else{
                    val = n;
                }
            }
            for (int i = 0;i<m;i++){
                if (arr[i] == val){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
            }
        }
        cout << ans << endl;
    }
}