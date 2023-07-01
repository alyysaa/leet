#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) { 
                maxArea = max(maxArea, height[left] * (right - left)); // area calculation (lowest height * distance)
                left++;
            } else {

                maxArea = max(maxArea, height[right] * (right - left));
                right--;
            }
        }
        return maxArea;
    }
};
