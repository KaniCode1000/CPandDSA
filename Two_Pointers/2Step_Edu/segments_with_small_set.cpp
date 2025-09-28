#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for (int i =0;i<n;i++){
		cin >> arr[i];
	}
	unordered_map<int,int> mp;
	long long num = 0;
	long long count = 0;
	int low = 0;
	for (int i = 0;i<n;i++){
		mp[arr[i]] += 1;
		if (mp[arr[i]] == 1){
			count += 1;
		}
		while (count > k && low < n){
			mp[arr[low]] -= 1;
			if (mp[arr[low]] == 0){
				count -= 1;
			}
			low++;
		}
		num += i-low+1;
	}
	cout << num << endl;
}
