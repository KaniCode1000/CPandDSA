#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
	vector<int> b; //binary indexed tree
	int n;

	FenwickTree(int n){
		this->n = n;
		b.assign(n,0);
	}

	FenwickTree(const vector<int> &a) : FenwickTree(a.size()){
		for (int i = 0;i<n;++i){
			b[i] += a[i];
			int r = i | (i+1);
			if (r < n) b[r] += b[i];
		}
	}

	int sum(int r){
		int res = 0;
		for (; r>=0; r = (r & (r+1)) -1){
			res += b[r];
		}
		return res;
	}

	int sum(int l,int r){
		return sum(r) - sum(l-1);
	}

	void add(int index,int delta){
		for (; index < n; index|= index+1)
			b[index] += delta;
	}
};

int main(){
	//Using size constructor
	FenwickTree ft(5);
	ft.add(0, 1);
	ft.add(1, 2);
	ft.add(2, 3);

	cout << ft.sum(2) << '\n';     // 6
	cout << ft.sum(1, 2) << '\n';  // 5
	
	vector<int> a = {1, 2, 3, 4, 5};

	FenwickTree ft1(a);

	cout << ft1.sum(4) << '\n';     // 15
	cout << ft1.sum(2, 4) << '\n';  // 12	
	return 0;
}

