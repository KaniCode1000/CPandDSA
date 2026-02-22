#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t!=0){
        t -= 1;
        int n;
        cin >> n;
        int z = 2*n;
        int ans[z];
        int arr[n];
        int total = (z*(z+1))/2;
        for (int i = 0;i<n;i++){
            cin >> ans[i+1];
            total -= ans[i+1];
        }
        for (int j = 0;j<n-1;j++){
            for (int i = 0;i<n;i++){
                cin >> arr[i];
            }
            total -= arr[n-1];
            ans[n+j+1] = arr[n-1]; 
        }
        ans[0] = total;
        for (int i = 0;i<z;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}