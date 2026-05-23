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

vector<int> lcp_array(string s, vector<int>& p) {
    s += '$';
    int n = s.size();

    vector<int> rnk(n);
    for (int i = 0; i < n; i++) rnk[p[i]] = i;

    vector<int> lcp(n - 1, 0);
    int k = 0;
    for (int i = 0; i < n; i++) {
        int pos = rnk[i];
        if (pos == n - 1) { k = 0; continue; }
        int j = p[pos + 1];
        while (max(i, j) + k < n && s[i + k] == s[j + k]) k++;
        lcp[pos] = k;
        if (k) k--;
    }
    return lcp;
}

int main() {
	ios::sync_with_stdio(false);
    	cin.tie(nullptr);

    	string so,t;
    	cin >> so >> t;
	string s = so + '#' + t;
	int n = s.size();
	int sn = so.size();
	vector<int> p   = suffix_array(s);
	vector<int> lcp = lcp_array(s, p);
	long long maxval = 0;
	string soln = "";
	int pos = 0;
	for (int i = 0;i<n;++i){
		if (lcp[i] > maxval && ((p[i] < sn) != (p[i+1] < sn))){
			maxval = lcp[i];
			pos = p[i];
		}	
	}
	soln = s.substr(pos,maxval);	
	cout << soln << endl;
	return 0;
}

