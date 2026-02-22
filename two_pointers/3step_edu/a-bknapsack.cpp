#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    long long s, A, B;
    cin >> n >> m >> s >> A >> B;

    long long a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    sort(a, a + n, greater<long long>());
    sort(b, b + m, greater<long long>());

    long long prefA[n+1], prefB[m+1];
    prefA[0] = 0;
    prefB[0] = 0;
    for (int i = 0; i < n; i++) prefA[i + 1] = prefA[i] + a[i];
    for (int j = 0; j < m; j++) prefB[j + 1] = prefB[j] + b[j];

    long long ans = 0;
    int j = m;

    for (int i = 0; i <= n; i++) {
        long long weightA = ((long long) i * A);
        if (weightA > s) break;
        while (j > 0 && weightA + ((long long) j * B) > s) j--;
        ans = max(ans, prefA[i] + prefB[j]);
    }

    cout << ans << "\n";
    return 0;
}
