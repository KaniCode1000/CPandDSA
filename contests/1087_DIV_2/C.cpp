#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int query;
        cout << "? 2 3" << endl;
        cout.flush();
        cin >> query;
        if (query == 1){
            cout << "! 2" << endl;
            cout.flush();
            continue;
        }
        cout << "? 1 2" << endl;
        cout.flush();
        cin >> query;
        if (query == 1){
            cout << "! 2" << endl;
            cout.flush();
            continue;
        }
        cout << "? 1 3" << endl;
        cout.flush();
        cin >> query;
        if (query == 1){
            cout << "! 3" << endl;
            cout.flush();
            continue;
        }
        bool done = false;
        for (int i = 4; i<= 2*n - 1;i+=2){
            cout << "? " << i << " " << i+1 << endl;
            cout.flush();
            cin >> query;
            if (query == 1){
                cout << "! " << i << endl;
                cout.flush();
                done = true;
                break;
            }
        }
        if (done){
            continue;
        }
        cout << "! " << 2*n << endl;
        cout.flush();
    }
}