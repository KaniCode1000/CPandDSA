#include <iostream>
using namespace std;

/*
Question: Check whether input n is prime or not
Answer: Using the fact that after 2 and 3 all prime numbers are of the form 6k+1 or 6k-1(same as 6k+5)
	as 6k+2 and 6k+4 are divisible by 2 and 6k+3 by 3.
*/

bool isPrime(int n){
	if (n == 2 || n == 3){
		return true;
	}
	else if (n%2 == 0 || n%3 == 0 || n <= 1){
		return false;
	}
	else{
		for (int i = 5; i*i <= n; i+=6){
			if (n%i == 0 || n% (i+2) == 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	isPrime(11) ? cout << "true\n" : cout << "false\n";
	isPrime(15) ? cout << "true\n" : cout << "false\n";
}
