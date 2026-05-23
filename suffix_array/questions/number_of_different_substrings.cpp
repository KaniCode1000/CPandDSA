#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s) {
    s += '$';
    int n = s.size();
    const int ALPHA = 256;

    vector<int> p(n), c(n), freq(max(ALPHA, n), 0);

    for (int i = 0; i < n; i++) freq[(unsigned char)s[i]]++;
    for (int i = 1; i < ALPHA; i++) freq[i] += freq[i - 1];
    for (int i = 0; i < n; i++) p[--freq[(unsigned char)s[i]]] = i;

    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(freq.begin(), freq.begin() + classes, 0);
        for (int i = 0; i < n; i++) freq[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) freq[i] += freq[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--freq[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int,int> cur  = { c[p[i]],     c[(p[i]     + (1 << h)) % n] };
            pair<int,int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n] };
            if (cur != prev) classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
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

    	string s;
    	cin >> s;
	int n = s.size();
	vector<int> p   = suffix_array(s);
	vector<int> lcp = lcp_array(s, p);
	long long value = (((long long) n)*(((long long) n)+1))/2;
	for (int i =0;i<n;++i){
		value -= lcp[i];
	}
	cout << value << endl;
	return 0;
}

