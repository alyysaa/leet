#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        bool dp[sLen + 1][pLen + 1];
        // initialize dp table
        for (int i = 0; i <= sLen; i++) {
            for (int j = 0; j <= pLen; j++) {
                dp[i][j] = false;
            }
        }
        dp[sLen][pLen] = true;
        for (int i = sLen; i >= 0; i--) { // every character in s
            for (int j = pLen - 1; j >= 0; j--) { // every character in p
                // true if the chracters at i,j are the same, or if the wildcard "."
                bool first_match = (i < sLen && (p[j] == s[i] || p[j] == '.'));

                //handles * case, if p[j+1] is * we can either skip it or skip the first character of s
                if (j + 1 < pLen && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0]; // the first character of s and p, true if they match
    }
};