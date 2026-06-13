#include <bits/stdc++.h>
using namespace std;

struct SegTree {
	int n;
	vector<int> t;

	// Constructor to initialize an empty tree of size n
	SegTree(int n) : n(n), t(2 * n, 0) {}

	// Constructor to build directly from an existing vector
	SegTree(const vector<int>& a) {
		n = a.size();
		t.assign(2 * n, 0);
		build(a, 1, 0, n - 1);
	}

	void build(const vector<int>& a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			int tm = (tl + tr) / 2;
			int left = v + 1;
			int right = v + 2 * (tm - tl + 1);

			build(a, left, tl, tm);
			build(a, right, tm + 1, tr);

			t[v] = t[left] + t[right];
		}
	}

	// Internal query function
	int sum(int v, int tl, int tr, int l, int r) {
		if (l > r) 
			return 0;
		if (l == tl && r == tr) {
			return t[v];
		}
		int tm = (tl + tr) / 2;
		int left = v + 1;
		int right = v + 2 * (tm - tl + 1);

		return sum(left, tl, tm, l, min(r, tm))
			+ sum(right, tm + 1, tr, max(l, tm + 1), r);
	}

	// Public wrapper for range sum queries [l, r]
	int query(int l, int r) {
		return sum(1, 0, n - 1, l, r);
	}

	// Internal update function
	void update_internal(int v, int tl, int tr, int pos, int new_val) {
		if (tl == tr) {
			t[v] = new_val;
		} else {
			int tm = (tl + tr) / 2;
			int left = v + 1;
			int right = v + 2 * (tm - tl + 1);

			if (pos <= tm)
				update_internal(left, tl, tm, pos, new_val);
			else
				update_internal(right, tm + 1, tr, pos, new_val);

			t[v] = t[left] + t[right];
		}
	}

	// Public wrapper for point updates
	void update(int pos, int new_val) {
		update_internal(1, 0, n - 1, pos, new_val);
	}
};

int main() {
	vector<int> a = {1, 3, 5, 7, 9, 11};

	// Initialize and build the tree
	SegTree st(a);

	// Query range sum from index 1 to 3 (3 + 5 + 7 = 15)
	int s1 = st.query(1, 3); 

	// Update index 2 (value 5) to 10
	st.update(2, 10); 

	// Query range sum from index 1 to 3 again (3 + 10 + 7 = 20)
	int s2 = st.query(1, 3); 
}
