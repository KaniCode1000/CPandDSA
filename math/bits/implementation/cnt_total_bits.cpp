#include <bits/stdc++.h>

using namespace std;

//Count number of set bits till a number n

int cnttotalsetbits(int n){
	int count = 0;
  	while (n > 0) {
        	int x = 31 - __builtin_clz(n);
       		count += x * (1 << (x - 1));
       		n -= 1 << x;
        	count += n + 1;
    	}
    	return count;
}

int main(){
	int n;
	cin >> n;
	n = cnttotalsetbits(n);
	cout << n << endl;
}
