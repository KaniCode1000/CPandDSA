#include <iostream>
using namespace std;

int main(){
	long x = 1000*1000*1000 + 7;
	int n;
	long ans = 1;
	cin >> n;
	for (int i = 0; i < n;i++){
		ans *= 2;
		ans %= x;
	}
	cout << ans;

}
