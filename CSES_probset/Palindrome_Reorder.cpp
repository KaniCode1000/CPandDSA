#include <iostream>
using namespace std;

int main(){
	string n;
	cin >> n;
	int arr[26] = {0};
	for (char &ch: n){
		arr[ch-'A'] += 1; 
	}	
	int countodd = 0;
	char odd_str = n[0];
	for (int i = 0;i<26;i++){
		if (arr[i]%2){
			countodd += 1;
			odd_str = ('A'+i);
		}
	}
	if (countodd > 1){
		cout << "NO SOLUTION";
	}
	else{
		char newarr[n.size()];
		int k =0;
		for (int i = 0;i<26;i++){
			if (arr[i] >= 2){
				for (int j =0;j<arr[i]/2;j++){
					newarr[k] = ('A'+i);
					newarr[n.size()-1-k] = ('A'+i);
					k++;
				}
			}
		}
		if (countodd == 1){
			newarr[(n.size()-1)/2] = odd_str;	
		}
		for (auto i = 0;i<n.size();i++){
			cout << newarr[i];
		}
	}
}
