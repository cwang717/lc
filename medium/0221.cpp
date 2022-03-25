class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int result = 0;
        
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i<m; ++i) {
            dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            result = max(result, dp[i][0]);
        }
        for (int i = 0; i<n; ++i) {
            dp[0][i] = (matrix[0][i] == '1') ? 1 : 0;
            result = max(result, dp[0][i]);
        }
        
        for (int i = 1; i<m; ++i) {
            for (int j = 1; j<n; ++j) {
                int temp = min(dp[i][j-1], dp[i-1][j]);
                temp = min(temp, dp[i-1][j-1]);
                dp[i][j] = (matrix[i][j] =='1') ? temp+1 : 0;
                result = max(result, dp[i][j]);
            }
        }
        
        return result*result;        
    }
};