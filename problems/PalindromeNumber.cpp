#include <limits.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        long long int res = 0;
        long long int y = x;
        while (y != 0) {
            res = res * 10 + y % 10;
            y /= 10;
        }
        return res == x;
    }
};