#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t != 0){
        t--;
        long long n;
        cin >> n;
        long long count = 0;
        long long arr[n];
        long long maxi = 0;
        for (int i = 0;i<n;i++){
            cin >> arr[i];
            maxi = max(maxi,arr[i]);
            if (i%2==1){
                arr[i] = maxi;
            }
            else if(i!=0){
                count += max((long long) 0,1+arr[i]-arr[i-1]);
            }
        }
        if (arr[0] == arr[1]){
            count++;
        }
        cout << count << endl;
    }
}