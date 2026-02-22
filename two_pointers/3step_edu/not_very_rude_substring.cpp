#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n, c;
    cin >> n >> c;
    string s;
    cin >> s;

    long long low = 0, rudeness = 0, cntA = 0, cntB = 0;
    long long maxlen = 0;
    long long arr[n];
    long long ac = 0;
    for (int i = 0;i<n;i++){
        if (s[i] == 'a'){
            ac += 1;
        }
        arr[i] = ac;
    }

    for (long long r = 0; r < n; r++) {
        if (s[r] == 'a') {
            cntA++;
        } 
        else if (s[r] == 'b') {
            rudeness += cntA;
            cntB++;
        }

        while (rudeness > c) {
            if (s[low] == 'a') {
                cntA--;
                rudeness -= cntB;
            } 
            if (s[low] == 'b'){
                cntB--;
            }
            low++;
        }

        maxlen = max(maxlen, r - low + 1);
    }

    cout << maxlen << endl;
    return 0;
}
