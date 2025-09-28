#include <iostream>
using namespace std;

int main(){
	long long i = 0;
	long long j = 0;
	long long count = 0;
	long long total = 0;
	int n,m;
	cin >> n;
	cin >> m;
	long long a[n];
	long long b[m];
	for (int k = 0;k<n;k++){
		cin >> a[k];
	}

	for (int k = 0;k<m;k++){
		cin >> b[k];
	}
	while (j!=m){
		if (a[i] < b[j]){
			i++;
			count = 0;
		}
		else if (i<n && a[i] == b[j]){
			i++;
			count++;
			if (i==n || a[i] != b[j]){
				total += count;
			}
		}
		else if (a[i] > b[j]){
			j++;
			if (count != 0 && b[j] == b[j-1]){
				total += count;
			}
			else{
				count = 0;
			}
		}
		else if (i==n && count != 0){
			j++;
			if (j<m && b[j] == b[j-1]){
				total += count;
			}
		}
		else{
			break;
		}
	}
	cout << total;
}
