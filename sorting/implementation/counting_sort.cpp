#include <iostream>
#include <algorithm>

using namespace std;

void counting_sort(int arr[],int n){
	int maxo = arr[0];
	
	//find max element
	for (int i = 0;i < n;i++){
		maxo = max(arr[i],maxo);
	}

	//freq array and ans array
	int ans[n];
	int freq[maxo+1];
	for (int i = 0;i<maxo+1;i++){
		freq[i] = 0;
	}

	for (int i = 0;i<n;i++){
		freq[arr[i]]++;
		ans[i] = arr[i];
	}

	//prefix sum
	for (int i = 1;i<maxo+1;i++){
		freq[i] += freq[i-1];
	}
	
	//reconstruct new soln
	for (int i = n-1; i>=0;i--){
		arr[freq[ans[i]]-1] = ans[i];
		freq[ans[i]]--;
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0;i<n;i++){
		cin >> arr[i];
	}
	counting_sort(arr,n);
	for (int i = 0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

