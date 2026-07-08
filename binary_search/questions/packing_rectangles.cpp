#include <bits/stdc++.h>
using namespace std;

// A. Packing Rectangles - Step2 Edu Codeforces

long long sqrootll(long long val){
	if (val == 0 || val == 1)
		return val;

	long long low = 0,high = val/2, ans = 0;
	while (low <= high){
		long long mid = low + (high-low)/2;
		long long square = mid*mid;

		if (square == val){
			return mid;
		}
		else if (square < val){
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid-1;
		}
	}
	return ans;
}

int main(){
	long long w,n,h;
	cin >> w >> h >> n;
	if (h > w){
		swap(w,h);
	}
	long long sqrtn = sqrootll(n);
	long long low = h*sqrtn, high = w*n;
	long long ans = low;
	while (low <= high){
		long long mid = low + (high-low)/2;
		if ((mid/h) != 0 && (mid/w) >= (n + (mid/h) -1)/(mid/h)){
			ans = mid;
			high = mid-1;	
		}
		else{
			low = mid+1;
		}
	}
	cout << ans << '\n';
	  
}
