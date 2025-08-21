#include <iostream>
#include <map>

using namespace std;

int main(){
	int t,n;
	cin >> t;
	while (t!=0){
		t-=1;
		cin >> n;
		int log[n];
		int arr[n];
		int count = 0;
		for (int i = 0;i<n;i++){
			cin >> arr[i];
			arr[i] -= 1;
			log[arr[i]] = i;
		}
		for (int i = 0;i<n;i++){
			if (arr[i] == i){
				continue;
			}
			else if (arr[arr[i]] == i){
				continue;
			}
			else{
				int k = arr[arr[i]];
				int ss = log[i];
				swap(arr[arr[i]],arr[ss]);
				log[i] = arr[i];
				log[k] = ss;
				count += 1;
			}
		}
		cout << count << endl;
	}
}
