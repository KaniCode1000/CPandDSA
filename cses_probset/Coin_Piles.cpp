#include <iostream>
using namespace std;

int main(){
	long a,b;
	int t;
	cin >> t;
	while (t!=0){
		t-=1;
		cin >> a;
		cin >> b;
		if (max(a-b,b-a) > min(a,b) || (a+b)%3 != 0){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}

}
