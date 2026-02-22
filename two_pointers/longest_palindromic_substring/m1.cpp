#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.size();
        int start = 0;
        int low =0;
        int high = 0;
        int maxlen = 1;
        for (int i = 0;i<slen;i++){
            for (int j = 0;j<2;j++){
                low = i;
                high = i+j;
                while (low >= 0 && high <= slen && s[low] == s[high])
                {
                    int currlen = high-low+1;
                    if (currlen > maxlen){
                        maxlen = currlen;
                        start = low;
                    }
                    high += 1;
                    low -= 1;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
