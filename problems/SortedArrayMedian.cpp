#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int> &nums1, vector<int> &nums2, int x) {
        int i = 0, j = 0, k = 1;
        if (x == 0) return x;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                if (k == x) return nums1[i];
                i++;
            } else {
                if (k == x) return nums2[j];
                j++;
            }
            k++;
        }
        while (i < nums1.size()) {
            if (k == x) return nums1[i];
            i++;
            k++;
        }
        while (j < nums2.size()) {
            if (k == x) return nums2[j];
            j++;
            k++;
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        int x;
        if (total & 1) {
            x = total / 2 + 1;
            return find(nums1, nums2, x);
        }
        x = total / 2;
        return (find(nums1, nums2, x) + find(nums1, nums2, x + 1)) / 2.0;
    }
};
