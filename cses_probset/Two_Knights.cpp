#include <iostream>
using namespace std;

long ways_count(int k){
	long n = k*k;
	if (k == 1){
		return 0;
	}
	else if (k==2){
		return 6;
	}
	long tot_ways = ((n*(n-1))/2) - ((k-1)*(k-2)*4);
	return tot_ways;
}

int main(){
	int k;
	cin >> k;
	for (int i = 1;i<=k;i++){
		cout << ways_count(i) << endl;
	}
}
