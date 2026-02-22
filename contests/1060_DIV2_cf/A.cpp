#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t != 0){
        t--;
        int n,k;
        cin >> n >> k;
        string word;
        cin >> word;
        int count = 0;
        int last_pos = -1;
        for (int i = 0;i<n;i++){
            if (word[i] == '1'){
                if (last_pos < 0 || i-last_pos >= k){
                    count += 1;
                }
                last_pos = i;
            }
        }
        cout << count << endl;
    }
}