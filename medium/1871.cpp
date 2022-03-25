class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for (int i = minJump; i<=maxJump; ++i) {
            dp[i] = s[i] == '0';
        }
        int left = 1, right = 1, count=0;
        while (right <= maxJump+1-minJump) {
            count += (dp[right++]) ? 1 : 0;
        }
        //cout << count << endl;
        for (int i = maxJump+1; i<s.size(); ++i) {
            dp[i] = s[i]=='0' && count>0;
            count -= (dp[left++]) ? 1 : 0;
            count += (dp[right++]) ? 1 : 0;
            //cout << count << endl;
        }
        
        return dp[s.size()-1];
    }
};