#include <iostream>
using namespace std;

int main(){
  long n;
  cin >> n;
  long arr[n-1];
  for (int i = 0;i<n-1;i++){
    cin >> arr[i];
  }
  int boolean = 0;
  long total = 0;
  for (auto i: arr){
    if (boolean == 1){
    	total += n;	
    }
    total -= i;
    boolean = boolean^1;
  }
  total += n;
  if (n%2 == 0){
  	total += n/2;
  }
  cout << total;
}
