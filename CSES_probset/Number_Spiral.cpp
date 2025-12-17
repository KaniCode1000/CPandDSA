#include <iostream>
using namespace std;

long num_spiral(long y, long x) {
    long n = max(y, x);
    bool odd = n % 2;
    long val;

    if (y == n) {
        val = (!odd) ? n * n - x + 1 : (n - 1) * (n - 1) + x;
    } else {
        val = (!odd) ? (n - 1) * (n - 1) + y : n * n - y + 1;
    }

    return val;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long y, x;
        cin >> y >> x;
        cout << num_spiral(y, x) << endl;
    }
}

