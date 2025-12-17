#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (n%4 != 0 && (n+1)%4 != 0){
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		if (n%2){
			cout << n/2 << endl;
			cout << n << " ";
			for (int i = 2;i<(n+1)/2;i+=2){
				cout << i << " " << n-i << " " ;
			}
			cout << endl;
			cout << (n+1)/2 << endl;
			for (int i = 1;i<(n+1)/2;i+=2){
				cout << i << " " << n-i << " ";
			}
		}
		else {
			if (n%8 == 0){
				 cout << (n/2)+1 << endl;
				 cout << n/4 << " ";
				 for (int i = 1;i<n/2;i+=2){
				 	cout << i << " " << n-i << " ";
				 }
				 cout << endl;
				 cout << (n/2) - 1 << endl;
				 cout << n << " ";
				 for (int i = 2; i <= n/2; i+= 2){
				 	if (i!= (n/4)){
						cout << i << " ";
					}
					if (i != (n-i)){
						cout << n-i << " ";
					}
				 }
			}
			else {
				cout << (n/2) << endl;
				//odd
				cout << (n/2) << " ";
				for (int i = 1;i<(n/2);i+=2){
					if (i!= n/4){
						cout << i << " ";
					}
					cout << n-i << " ";
				}
				cout << endl;
				cout << (n/2) << endl;
				//even
				cout << n << " " << n/4 << " ";
				for (int i = 2; i < (n/2); i+=2){
					cout << i << " " << n-i << " ";
				}
			}
		}
	}
}

