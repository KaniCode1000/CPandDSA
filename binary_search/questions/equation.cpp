#include <bits/stdc++.h>
using namespace std;

// E. Equation - Step2 Codeforces Edu

int main(){
	double c; cin >> c;
	double l = 0, h = 1000;
	for (int i = 0;i<35;++i){
		double m = l + (h-l)/2;
		double value = (m*(m*m*m + 1) - c);
		if(value < 0){
			l = m;	
		}
		else{
			h = m;
		}
	}
	cout << setprecision(20) << l*l << '\n';
}
