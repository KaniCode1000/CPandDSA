#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int a[n];
  int b[m];
  for (int i = 0;i<n;i++){
    cin >> a[i];
  }

  for (int i = 0;i<m;i++){
    cin >> b[i];
  }
  int i = 0;
  int j = 0;
  while (i+j<m+n){
    if ((i<n && a[i] < b[j]) || j == m){
      i++;
    }
    else{
      cout << i << " ";
      j++;
    }
  }
}
