#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        int start = 0, len = 1;//all single characters are palindrome
        for (int i = 0; i < n;) {
            if (n - i <= len / 2) break;
            int j = i, k = i;
            while (k < n - 1 && s[k] == s[k + 1]) k++; //duplicate characters

            i = k + 1;// skip duplicate characters
            while (k < n - 1 && j > 0 && s[k + 1] == s[j - 1]) {
                k++;
                j--;
            }

            int newLen = k - j + 1;
            if (newLen > len) {
                start = j;
                len = newLen;
            }
        }
        return s.substr(start, len);
    }
};