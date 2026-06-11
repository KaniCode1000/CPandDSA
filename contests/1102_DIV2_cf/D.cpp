#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<bool> s1(n),s2(n);
		string x,y;
		cin >> x >> y;
		for (int i = 0;i<n;++i){
			if (x[i] == '1'){
				s1[i] = 1;
			}
			else{
				s1[i]=0;
			}
			if (y[i] == '1'){
				s2[i] = 1;
			}
			else{
				s2[i]=0;
			}
		}
		int cnt[2][2] = {{0,0},{0,0}};
		for (int i = 0;i<n;++i){
			cnt[s1[i]][s2[i]]++;
		}
		long long ans = 0;
		long long number = (1LL << k) + 1;
		ans += ((number+2)/3)*(cnt[1][0]+cnt[1][1])*(cnt[0][0]+cnt[0][1]) + ((number+(k%2))/3)*(cnt[0][1]+cnt[1][0])*(cnt[0][0]+cnt[1][1]) + ((number+ (k%2==0))/3)*(cnt[1][0]+cnt[0][0])*(cnt[0][1]+cnt[1][1]);
		cout << ans << '\n';	
		
	}	
}

