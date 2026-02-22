#include <iostream>
using namespace std;

int main(){
	long long n,s,k,summation;
    long long val = 0;
    summation = 0;
	cin >> n >> k;
	long long arr[2*n];
	for (long long i = 0;i<n;i++){
		cin >> arr[i];
        arr[n+i] = arr[i];
        summation += arr[i];
	}
    s = k % summation;
	long long summ = 0;
	long long low = 0,res = 2*n;
	for (long long r = 0;r<2*n;r++){
		summ += arr[r];
		while (summ - arr[low] >= s){
			summ -= arr[low];
			low++;
		}
		if (summ >= s){
            if (res > (r-low+1)){
                res = r-low+1;
                val = low;
            }
		}
	}
	cout << (val%n)+1 << " " << ((res) + (k/summation)*n)<< endl; //res % n fails for example in 4 38 [5 5 5 5] 
	
}

