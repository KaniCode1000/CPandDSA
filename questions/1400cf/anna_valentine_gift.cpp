#include <bits/stdc++.h>

using namespace std;

// 1931E. Anna and The Valentine's Day Gift - Codeforces

vector<long long> counting_sort(vector<long long> arr,int n){
	long long maxo = arr[0];
	
	//find max element
	for (int i = 0;i < n;i++){
		maxo = max(arr[i],maxo);
	}

	//freq array and ans array
	vector<long long> ans(n);
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
	return arr; 
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,m;
		cin >> n >> m;
		vector<long long> a(n);
		vector<long long> biga(n);
		long long temp;
		for (int i = 0;i<n;++i){
			cin >> temp;
			int p = 0,sp = 0;
			bool done = false;
			while (temp/10 != 0){
				p++;
				if (!done && temp % 10 == 0)
					sp++;
				else{
					done = true;
				}
				temp /= 10;
			}
			biga[i] = p;
			a[i] = sp;
		}
		vector<long long> ans = counting_sort(a,n);
		vector<long long> bigans = counting_sort(biga,n);
		/* for (int i = 0;i<n;++i){
			cout << ans[i] << " " << bigans[i] << '\n';
		} */
		long long summ = 0;
		for (int i = n-1;i>=0;i-=2){
			summ -= ans[i];	
		}
		for(int i = 0;i<n;++i){
			summ += biga[i]+1;
		}
		if (summ > m){
			cout << "Sasha" << '\n';
		}
		else{
			cout << "Anna" << '\n';
		}
	}

}
