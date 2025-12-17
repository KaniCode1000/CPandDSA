#include <iostream>
#include <cmath>

using namespace std;

void tower_of_hanoi(int num, int end, int aux,int start){
	if (num == 0){
		return;
	}
	tower_of_hanoi(num-1,aux,end,start);
	cout << start << " " << end << endl;
	tower_of_hanoi(num-1,end,start,aux);
}

int main(){
	int n;
	cin >> n;
	cout << (pow(2,n)-1) << endl;
	tower_of_hanoi(n,3,2,1);
}
