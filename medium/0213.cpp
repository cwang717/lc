class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) {return nums[0];}
        if (n==2) {return max(nums[0], nums[1]);}
        // if (n==3) {return max(max(nums[0], nums[1]), nums[2]);}
        
        vector<int> dp00(n);
        vector<int> dp01(n);
        vector<int> dp10(n);
        vector<int> dp11(n);
        dp00[2] = nums[1];
        dp01[2] = nums[2];
        dp10[2] = nums[0];
        dp11[2] = nums[0] + nums[2];
        
        for (int i=3; i<n; ++i) {
            dp00[i] = max(dp01[i-1], dp00[i-1]);
            dp01[i] = dp00[i-1] + nums[i];
            dp10[i] = max(dp10[i-1], dp11[i-1]);
            dp11[i] = dp10[i-1] + nums[i];
        }
        
        return max(max(dp00[n-1], dp01[n-1]), dp10[n-1]);
        
    }
};