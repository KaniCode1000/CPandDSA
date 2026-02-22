#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    string x;
    cin >> x;
    string y;
    cin >> y;
    int arr[26];
    for (int i = 0;i<26;i++){
        arr[i] = 0;
    }
    for (int i = 0;i<m;i++){
        arr[y[i]-'a'] += 1;
    }
    int low = 0;
    int temp = 0;
    long long val = 0;
    for (int r = 0;r<n;r++){
        temp = x[r] - 'a';
        arr[temp] -= 1;
        while (arr[temp] < 0 && low<=r){
            arr[x[low]-'a'] += 1;
            low++;
        }
        val += (long long) r-low+1;  
    }
    cout << val << endl;
}