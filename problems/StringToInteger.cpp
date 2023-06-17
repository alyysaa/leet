#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int i = 0;
        while (i < size && s[i] == ' ') i++;
        if (i == size) return 0;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') i++;

        int res = 0;
        while (i < size && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0'; // convert char to int 
            if (res > INT_MAX / 10 || res < INT_MIN / 10) return sign == 1 ? INT_MAX : INT_MIN;
            if (res == INT_MAX / 10 && digit > 7) return sign == 1 ? INT_MAX : INT_MIN;
            if (res == INT_MIN / 10 && digit < -8) return sign == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
};