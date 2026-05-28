#include <bits/stdc++.h>

using namespace std;

// To count the number of set bits in the a number n.

int cntsetbits(int n){
	int count = 0;
	while (n){
		count++;
		n &= n-1;
	}
	return count;
}

int main(){

}
