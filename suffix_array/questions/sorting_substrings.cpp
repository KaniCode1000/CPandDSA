#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s){
	s += '$';
	int n = s.size();
	const int alphabet = 256;
	vector<int> p(n),c(n), freq(max(alphabet,n),0); // permutation array and equivalence classes array

	//k = 0 (1 len string) counting sort

	for (int i = 0;i < n;i++){
		freq[s[i]]++;
	}
	
	for (int i = 1;i < alphabet; i++){
		freq[i] += freq[i-1];
	}
	for (int i = 0; i < n; i++){
		p[--freq[s[i]]] = i;
	}

	//assigning classes

	c[p[0]] = 0;
	int classes = 1;

	for (int i = 1;i < n;i++){
		if (s[p[i]] != s[p[i-1]]){
			classes++;
		}
		c[p[i]] = classes-1;
	}

	//transition from 2^k to 2^(k+1) strings

	vector<int> ptemp(n),ctemp(n);

	//primary loop for log of length of strings
	for (int h = 0; (1 << h) < n; ++h){
		//sorting using radix sort
		for (int i = 0;i < n;i++){
			//offsetting the p[i] index to the beginning of left half of the 2^(k+1) string
			ptemp[i] = p[i] - (1 << h); //p[i] is trivially sorting of right half, now to sort left half
			if (ptemp[i] < 0){
				ptemp[i] += n;
			}
		}
		fill(freq.begin(),freq.begin()+classes,0);
		//repeat of counting sort over left 2^k strings
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

		//class assignment
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
	int n = s.size();
	vector<int> p(1+n);
	p = suffix_array(s);
	int N;
	cin >> N;
	vector<tuple<int,int,int,int>> ans(N);
	int l,r;
	for (int i = 0;i<N;++i){
		cin >> l >> r;
		ans[i] = {p[l-1],r-l+1,l,r};
	}
	vector<tuple<int,int,int,int>> sorted_ans(N);
	for (int k = 3; k >= 0;--k){
		vector<int> freq(n+1,0);
		for (int i = 0;i<N;++i){
			freq[get<k>(ans[i])]++;	
		}
		for (int i = 1;i<=n;++i){
			freq[i] += freq[i-1];
		}
		for (int i = N-1;i>=0;--i){
			sorted_ans[--freq[get<k>(ans[i])]] = ans[i];
		}
		ans.swap(sorted_ans);
	}
	for (int i = 0;i<N;++i){
		cout << get<2>(ans[i]) << " " << get<3>(ans[i]) << endl;
	}
}

