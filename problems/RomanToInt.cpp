#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int result = 0, size = s.size(), i = 0;
        // reordered roman numerals to make it easier to check for 2 character numerals
        vector< pair < string, int > > roman = { {"M", 1000},  {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
                                            {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9},
                                            {"V", 5}, {"IV", 4}, {"I", 1} };
        for (auto &p : roman) {
            if (p.first.size() == 2) {
                if (i + 1 < size && s.substr(i, 2) == p.first) {
                    result += p.second;
                    i += 2;
                }
            } else // 1 character numerals
                while (i < size && s[i] == p.first[0]) {
                    result += p.second;
                    i++;
                }
        }
        return result;
    }
};

#include <iostream>
int main() {
    Solution s;
    string input = "MCMXII";
    cout << s.romanToInt(input);
    return 0;
}