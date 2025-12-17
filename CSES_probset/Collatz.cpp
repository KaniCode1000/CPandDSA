#include <iostream>
using namespace std;

void collatz_series(long n){
	while (n!=1){
		cout << n << " "; 
		if (n%2 == 0){
			n /= 2;
		}
		else{
			n = 3*n + 1;
		}
	}
	cout << 1;
}

int main(){
	long num;
	cin >> num;
	collatz_series(num);
}
