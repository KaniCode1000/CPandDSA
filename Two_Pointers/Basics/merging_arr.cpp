#include <iostream>
using namespace std;
 
int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;
    int a[n];
    int b[m];
    int c[m+n];
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    for (int i = 0;i<m;i++){
        cin >> b[i];
    }
    int i =0;
    int j =0;
    while (i+j < (m+n)){
        if ((i<n && a[i]<b[j]) || j == m){
            c[i+j] = a[i];
            i++;
        }
        else{
            c[i+j] = b[j];
            j++;
        }
    }
    for (int k = 0;k<m+n;k++){
        cout << c[k] << " ";
    }
}
