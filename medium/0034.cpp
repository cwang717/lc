using namespace std;

#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        
        //find left bound
        int left = 0, right = nums.size()-1;
        while (right > left + 1) {
            int mid = (left + right)/2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int leftBound = -1;
        if (nums[right] == target) {
            leftBound = right;
        }
        if (nums[left] == target) {
            leftBound = left;
        }

        
        //find right bound
        left = 0;
        right = nums.size()-1;
        while (right > left + 1) {
            int mid = (left + right)/2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int rightBound = -1;
        if (nums[left] == target) {
            rightBound = left;
        }
        if (nums[right] == target) {
            rightBound = right;
        }
        
        return vector<int>{leftBound, rightBound};
    }
};