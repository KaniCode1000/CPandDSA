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

	Fenwickrupq(const vector<int> &d,bool done) : Fenwickrupq(d.size()){
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

struct Fenwickrurq{
	int n;
	Fenwickrupq b1,b2;

	Fenwickrurq(int n) : n(n),b1(n),b2(n) {}
	Fenwickrurq(const vector<int> &a) : n(a.size()),b1(n),b2(n) {
		vector<int> d(n);
		d[0] = a[0];

		for (int i = 1;i<n;++i)
			d[i] = a[i] - a[i-1];

		vector<int> wd(n);
		for (int i = 0;i<n;++i)
			wd[i] = d[i]*i;
		bool done = true;
		b1 = Fenwickrupq(d,done);
		b2 = Fenwickrupq(wd,done);
	}
	
	void range_add(int l,int r, int delta){
		b1.range_add(l,r,delta);
		b2.add(l,l*delta);

		if (r+1 < n){
			b2.add(r+1,-delta*(r+1));
		}
	}

	long long prefix_sum(int r){
		if (r<0) return 0;

		return 1LL*(r+1)*b1.sum(r) - b2.sum(r);
	}
	
	long long range_sum(int l,int r){
		return prefix_sum(r) - prefix_sum(l-1);
	}
};

int main(){
	vector<int> a = {5, 8, 3, 10, 7};

	Fenwickrurq ft(a);

	cout << ft.range_sum(1,3) << '\n'; // 21

	ft.range_add(1,3,4);

	cout << ft.range_sum(1,3) << '\n'; // 33
	cout << ft.range_sum(0,4) << '\n'; // 45
}
