#include <bits/stdc++.h>
using namespace std;


#define int long long


signed main(){
    int t; cin >> t;
    while (t--){
        long long n,x; cin >> n >> x;
		
        auto check = [=](long long n,long long m,long long x)->long long {
            long long done = 1;
            for (int k = 0;k<=62;++k){
                long long pow = (1LL << k);
                long long val = pow - (n&(pow-1));

                if ((pow & x) == 0 && (pow & n) != 0){
                    if (m - n < val){
                        return 2;
                    }
                }
                else if ((pow & x) != 0){
                    if (m - n >= val){
                        return 0;
                    }
                }
            }
            return done;
        };

        long long ans = -1;
        if ((n & x) != x){
            cout << -1 << '\n';
            continue;
        }
        else if (n == x){
            cout << n << '\n';
            continue;
        }

        long long low = n, high = 5e18;
        while (low <= high){
            long long mid = low + (high - low)/2;
            long long val = check(n,mid,x);

            if (val == 1){
                ans = mid;
                high = mid-1;
            }
            else if (val == 0){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        cout << ans << '\n';
    }
}