#include <iostream>
#include <cstring>
using namespace std;


int main(){
	string inp;
	cin >> inp;
	int count = 0;
	int maxcount = 0;
	if (inp == ""){
		cout << 0;
		return 0;
	}
	char prev = '\0';
	for (char i: inp){
		if (i == prev){
			count += 1;
		}
		else{
			count =0;
		}
		prev = i;
		maxcount = max(count,maxcount);
	}
	cout << maxcount+1;
}
