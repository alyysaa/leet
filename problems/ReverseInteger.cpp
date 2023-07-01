#include<limits.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
            if (res == INT_MAX / 10 && digit > 7) return 0; //prevent overflow
            if (res == INT_MIN / 10 && digit < -8) return 0; //prevent underflow
            res = res * 10 + digit;
        }
        return res;
    }

};