#include <iostream>
using namespace std;

int main(){
	int t,n;
	cin >> t;
	while (t!=0){
		t--;
		cin >> n;
		int a[n];
		for (int i = 0;i<n;i++){
			cin >> a[i];
		}
		bool non_dec = true;
		int ans = 0;
		for (int i = n-2;i> -1;i--){
			if (non_dec && a[i] < a[i+1]){
				non_dec = false;
			}
			else if(!non_dec && a[i] > a[i+1] ){
				ans = i+1;
				break;	
			}
		}
		cout << ans << endl;
	}
}
