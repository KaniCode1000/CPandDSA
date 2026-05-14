#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s){
	s += '$';
	int n = s.size();
	const int alphabet = 256;
	vector<int> p(n),c(n), freq(max(alphabet,n),0);

	//k = 0 sorting

	for (int i = 0;i < n;i++){
		freq[s[i]]++;
	}
	
	for (int i = 1;i < alphabet; i++){
		freq[i] += freq[i-1];
	}
	for (int i = 0; i < n; i++){
		p[--freq[s[i]]] = i;
	}
	c[p[0]] = 0;
	int classes = 1;

	for (int i = 1;i < n;i++){
		if (s[p[i]] != s[p[i-1]]){
			classes++;
		}
		c[p[i]] = classes-1;
	}

	vector<int> ptemp(n),ctemp(n);

	for (int h = 0; (1 << h) < n; ++h){
		for (int i = 0;i < n;i++){
			ptemp[i] = p[i] - (1 << h);
			if (ptemp[i] < 0){
				ptemp[i] += n;
			}
		}
		fill(freq.begin(),freq.begin()+classes,0);
		for (int i = 0;i<n;i++){
			freq[c[ptemp[i]]]++;
		}
		for (int i = 1;i<classes;i++){
			freq[i] += freq[i-1];
		}
		for (int i = n-1;i>=0;i--){
			p[--freq[c[ptemp[i]]]] = ptemp[i]; 
		}
		ctemp[p[0]] = 0;
		classes = 1;
		for (int i = 1;i<n;i++){
			pair<int,int> cur = {c[p[i]], c[(p[i] + (1<<h))%n]};
			pair<int,int> prev = {c[p[i-1]],c[(p[i-1] + (1<<h))%n]};
			if (cur != prev){
				++classes;
			}
			ctemp[p[i]] = classes-1;
		}
		c.swap(ctemp);
	}
	return p;
}

int main(){
	string s;
	cin >> s;
	int q;
	cin >> q;
	int n = s.size();
	vector<int> p(n+1);
	p = suffix_array(s);
	while (q--){
		string query;
		cin >> query;
		int m = query.size();
		if (m > n){
			cout << "No" << endl;
			continue;
		} 
		int low = 0;
		int high = n;
		while (low <= high){
			int mid = low + (high - low)/2;
			int comparision = s.compare(p[mid],m,query);
			if (comparision == 0){
				cout << "Yes" << endl;
				break;
			}
			else if (comparision < 0){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		if (low > high){
			cout << "No" << endl;
		}
	}
}

