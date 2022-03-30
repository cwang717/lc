class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxL = INT_MAX;
        for (int i=0; i<strs.size(); ++i) {
            maxL = min(maxL, (int)strs[i].length());
        }
        
        string result = "";
        for (int i=0; i<maxL; ++i) {
            char c = strs[0][i];
            for (int j=1; j<strs.size(); ++j) {
                if (strs[j][i] != c) return result;
            }
            result.push_back(c);
        }
        
        return result;
        
    }
};