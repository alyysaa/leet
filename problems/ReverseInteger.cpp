#include<iostream>
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

#include<iostream>
int main() {
    Solution s;

    cout << s.reverse(1534236469) << endl;
    int tests = 5;
    int nums[] = { 123456, -123089, 0, -10, 2147483647 };
    int sols[] = { 654321, -980321, 0, -1,  0 };
    for (int i = 0; i < tests; i++) {
        cout << nums[i] << " reversed as " << s.reverse(nums[i]) << " expected " << sols[i] << endl;
    }
}