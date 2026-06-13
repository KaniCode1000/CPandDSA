#include <bits/stdc++.h>

using namespace std;

struct FenwickTree2D {
	vector<vector<int>> b;
	int n,m;
	
	FenwickTree2D(int n,int m){
		this->n = n;
		this->m = m;
		b.assign(n,vector<int>(m,0));
	}

	FenwickTree2D(const vector<vector<int>> &a){
		n = a.size();
		m = (n ? a[0].size() : 0);
		
		b = a;
	
		for (int i = 0;i<n;++i){
			for (int j = 0;j < m; ++ j){
				int nexti = i|(i+1);
				int nextj = j|(j+1);

				if (nexti < n){
					b[nexti][j] += b[i][j];
				}	
				
				if (nextj < m)
					b[i][nextj] += b[i][j];
				
				if (nextj < m && nexti < n)
					b[nexti][nextj] -= b[i][j];			
			}
		}
	}
	
	//sum of rect (0,0) -> (x,y)
	int sum(int x,int y){
		int res = 0;
		for (int i = x; i>=0; i = (i&(i+1)) - 1){
			for (int j = y; j >= 0; j = (j&(j+1)) - 1){
				res += b[i][j];
			}
		}
		return res;
	}
		
	//sum of rect (x1,y1) -> (x2,y2)
	int sum(int x1,int y1,int x2,int y2){
		return sum(x2,y2) - sum(x1-1,y2) - sum(x2,y1-1) + sum(x1-1,y1-1);
	}
	
	//add query
	void add(int x,int y,int delta){
		for (int i = x;i<n;i |= (i+1)){
			for (int j = y; j < m; j |= j+1){
				b[i][j] += delta;
			}
		}
	}
};

int main(){
	vector<vector<int>> a = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	FenwickTree2D ft(a);

	cout << ft.sum(2, 2) << '\n';          // 45

	cout << ft.sum(1, 1, 2, 2) << '\n';    // 5+6+8+9 = 28

	ft.add(1, 1, 10);

	cout << ft.sum(1, 1, 2, 2) << '\n';    // 38
	return 0;
}
