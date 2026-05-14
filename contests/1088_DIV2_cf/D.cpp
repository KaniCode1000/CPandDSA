#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int n, k;
            cin >> n >> k;
            
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            
            vector<int> b(n);
            for (int i = 0; i < n; i++) {
                cin >> b[i];
            }

            bool notdone = true;
            unordered_map<int, int> pure_a_counts;
            unordered_map<int, int> forced_b_counts;

            for (int i = 0; i < k; i++) {
                
                bool is_pure = true;
                int first_a = a[i];
                for (int j = i; j < n; j += k) {
                    if (a[j] != first_a) {
                        is_pure = false;
                        break;
                    }
                }

                if (!is_pure) {
                    for (int j = i; j < n; j += k) {
                        if (b[j] != -1 && b[j] != a[j]) {
                            notdone = false;
                            break;
                        }
                    }
                } 
                else {
                    pure_a_counts[first_a]++;
                    
                    int b_val = -1;
                    for (int j = i; j < n; j += k) {
                        if (b[j] != -1) {
                            if (b_val == -1) {
                                b_val = b[j];
                            } else if (b_val != b[j]) {
                                notdone = false;
                                break;
                            }
                        }
                    }
                    if (b_val != -1) {
                        forced_b_counts[b_val]++;
                    }
                }
                
                if (!notdone){
                    break;
                } 
            }

            if (notdone) {
                for (auto pair : forced_b_counts) {
                    int val = pair.first;
                    int count = pair.second;
                    if (pure_a_counts[val] < count) {
                        notdone = false;
                        break;
                    }
                }
            }

            if (notdone) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}