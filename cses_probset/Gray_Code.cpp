#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
  int tot_value = 65536;
  string ans = "2222222222222222";
  string arr[tot_value];
  for (int i = 0;i<tot_value;i++){
  	arr[i] = ans;
  }
  int k = 0;
  int parity = 1;
  int curr_value = 1;
  while (k!=n){
    for (int i = 0;i < tot_value;i++){
	if (i%(curr_value*2) == 0){
		parity ^= 1;
	}	
	arr[i][k] = (((i % (2*curr_value))/curr_value  == 0))^parity ? '0' : '1';
    }
    k++;
    curr_value = pow(2,k);  
  }
  for (int j =0;j<curr_value;j++){
    for (int i = 0; i<k;i++){
      cout << arr[j][i];
    }
    cout << endl;
  }
}
