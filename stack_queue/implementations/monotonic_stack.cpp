#include <bits/stdc++.h>

using namespace std;

//For Nearest smaller element behind an index i

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	stack<pair<int, int>> stack;
	stack.push({0, 0}); //value ,index

	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		while (!stack.empty() && stack.top().first >= a) stack.pop();
		cout << stack.top().second << " ";
		stack.push({a, i});
	}
}
