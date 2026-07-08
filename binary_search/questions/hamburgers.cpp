#include <bits/stdc++.h>
using namespace std;

// H. Hamburgers - Step2 Codeforces Edu


int main(){
	string burg; cin >> burg;
	int bc = 0,sc = 0,cc = 0; 
	for (char x: burg){
		if (x == 'B'){
			bc++;
		}
		else if( x == 'S')
			sc++;
		else{
			cc++;
		}
	}
	int nb,ns,nc; cin >> nb >> ns >> nc;
	int pb,ps,pc; cin >> pb >> ps >> pc;
	
	long long r; cin >> r;
	
	long long l = 0, h= 1e13;
	long long ans = 0;

	while (l <= h){
		long long mid = l + (h-l)/2;
		long long totcost = max(1LL*0,(bc*mid - nb)*pb) + max(1LL * 0,(sc*mid - ns)*ps) + max(1LL*0,(cc*mid - nc)*pc);
		if (totcost <= r){
			ans = mid;
			l = mid+1;	
		}
		else{
			h = mid-1;
		}
	}
	cout << ans << '\n';
}
