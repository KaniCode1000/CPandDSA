#include <bits/stdc++.h>
using namespace std;

// C. Very Easy Task - Step2 Codeforces Edu

int main(){
	long long n,x,y; cin >> n >> x >> y;
	if (x > y)
		swap(x,y);
	if (n == 1)
		cout << x << '\n';
	else{
		long long time = x;
		long long low = 0, high = x*n-x;
		while (low <= high){
			long long mid = low + (high - low)/2;
			if (mid/x + mid/y >= n-1){
				time = x + mid;
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		cout << time << '\n';
	}
}
