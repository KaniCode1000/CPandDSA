#include <iostream>
using namespace std;

int main(){
	long n;
	cin >> n;
	long ans = 0;
	long x = 5;
	while (x <= n){
		ans += n/x;
		x *= 5;
	}
	cout << ans;
}
