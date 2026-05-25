#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	string a,b;
	cin >> a;
	cin >> b;
	int c[n+1][m+1];
	for (int i = 0;i<m;++i){
		c[0][i] = 0;
	}
	for (int i = 0;i<n;++i){
		c[i][0] = 0;
	}
	int soln = 0;
	for (int i = 1;i<=n;++i){
		for (int j = 1;j<=m;++j){
			if (a[i-1] == b[j-1]){
				c[i][j] = 2 + c[i-1][j-1];
				soln = max(c[i][j],soln);
			}
			else{
				c[i][j] = max(0,max(c[i-1][j],c[i][j-1])-1);
			}
		}
	}
	cout << soln << endl;
	
	
}
