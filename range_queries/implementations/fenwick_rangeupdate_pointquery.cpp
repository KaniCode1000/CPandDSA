#include <bits/stdc++.h>

using namespace std;

struct Fenwickrupq{
	vector<int> b;
	int n;
	
	Fenwickrupq(int n){
		this->n = n;
		b.assign(n,0);
	}

	Fenwickrupq(const vector<int> &a) : Fenwickrupq(a.size()){
		vector<int> d(n,0);
		d[0] = a[0];
		for (int i = 1;i<n;++i){
			d[i] = a[i]-a[i-1];
		}
		b = d;
		for (int i = 0;i<n;++i){
			int r = i | i+1;
			if (r<n)
				b[r] += b[i];
		}
	}
		
	void add(int index,int delta){
		for (; index < n; index |= index+1)
			b[index] += delta;
	}
	
	int sum(int r){
		int res = 0;
		for (; r >=0; r = (r & (r+1))-1){
			res += b[r];
		}
		return res;
	}

	void range_add(int l,int r, int delta){
		add(l,delta);
		if (r+1 < n){
			add(r+1,-delta);
		}
	}

	int point_query(int index){
		return sum(index);
	}
};

int main() {
	vector<int> a = {5, 8, 3, 10, 7};

	Fenwickrupq ft(a);

	cout << "Initial array:\n";
	for (int i = 0; i < (int)a.size(); ++i)
		cout << ft.point_query(i) << ' ';
	cout << "\n\n";

	ft.range_add(1, 3, 4);

	cout << "After adding 4 to [1,3]:\n";
	for (int i = 0; i < (int)a.size(); ++i)
		cout << ft.point_query(i) << ' ';
	cout << "\n\n";

	ft.range_add(0, 4, 2);

	cout << "After adding 2 to [0,4]:\n";
	for (int i = 0; i < (int)a.size(); ++i)
		cout << ft.point_query(i) << ' ';
	cout << "\n\n";

	ft.range_add(2, 2, -5);

	cout << "After adding -5 to [2,2]:\n";
	for (int i = 0; i < (int)a.size(); ++i)
		cout << ft.point_query(i) << ' ';
	cout << '\n';

	return 0;
}	
