#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        long long x;
        long long y;
        cin >> n;
        cin >> x;
        cin >> y;
        long long summation=0;
        vector<long long > vec(n);
        for(auto &k:vec){
            cin>>k;
            summation+=k;
        }
        sort(vec.begin(),vec.end());
        x=summation-x;
        y=summation-y;
        long long ans=0;
        for (int i = 0; i < n; ++i) {
            long long val = vec[i];

            auto it_y_low = lower_bound(vec.begin(), vec.end(), y - val);
            auto it_x_high = upper_bound(vec.begin(), vec.end(), x - val);

            int start = it_y_low - vec.begin();
            int end = it_x_high - vec.begin() - 1;

            int count = end - start + 1;
            if (count > 0) {
                ans += count;
            }

            if (i >= start && i <= end) {
                ans -= 1;
            }
        }

                cout<<ans/2<<endl;
    }
 
    return 0;
}