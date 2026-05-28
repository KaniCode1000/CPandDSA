#include <bits/stdc++.h>

using namespace std;

//1355C. Count Triangles - Codeforces

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	long long ans = 0;
	for (int i = 0; i <= c - a;++i){
		int x;
		x = min(i,min(b-a,c-b)) - max(i- (max(b-a,c-b)),0) + 1;
		int z = min(max(0,i+a+b - c),d-c+1);
		ans += (1LL * z)*x;	
	}	
	cout << ans << endl;
}
