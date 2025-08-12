#include <iostream>
using namespace std;

int main(){
  int c;
  long long x;
  cin >> c;
  long long y;
  long long n;
  for (int i=0;i<c;i++)
  { 
    cin >> x;
    cin >> y;
    cin >> n;
    x = x%m;
    long long ans = 1;
    while (y)
    {
      if (y&1)
        ans = (ans*x)%m;
      a = (a*a)%m;
      b >>= 1;
    }
    cout << ans << endl;
  }

}
