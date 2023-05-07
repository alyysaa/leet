#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, bool> map;
        for (int i = 0, j = 0; j < n; j++) {
            while (map[s[j]]) {
                map[s[i]] = false;
                i++;
            }
            map[s[j]] = true;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
