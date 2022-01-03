using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()<3) {return result;}
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                if (nums[left] + nums[right] > -nums[i]) {
                    --right;
                } else if (nums[left] + nums[right] < -nums[i]) {
                    ++left;
                } else {
                    while (left + 1 < right && nums[left+1] == nums[left]) {
                        ++left;
                    }
                    result.push_back(vector<int>{nums[i], nums[left++], nums[right]});
                }
            }
        }
        
        return result;
    }
};