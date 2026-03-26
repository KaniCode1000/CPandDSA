#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        long long r,g,b;
        char mini,maxi,mid;
        cin >> r >> g >> b;
        if (r > g){
            if (r > b){
                maxi = 'R';
                if (b > g){
                    mini = 'G';
                    mid = 'B';
                }
                else{
                    mini = 'B';
                    mid = 'G';
                }
            }
            else{
                maxi = 'B';
                mini = 'G';
                mid = 'R';
            }
        }
        else{
            if (r > b){
                mini = 'B';
                maxi = 'G';
                mid = 'R';
            }
            else{
                mini = 'R';
                if (b > g){
                    mid = 'G';
                    maxi = 'B';
                }
                else{
                    mid = 'B';
                    maxi = 'G';
                }
            }
        }

        vector<char> answer;

    }
}