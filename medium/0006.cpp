class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        int moder = numRows - 1;
        vector<string> strs(numRows, "");
        for (int i=0; i<s.length(); ++i) {
            int remain = i%moder;
            int remain2 = i%(moder*2);
            if (remain == remain2) {
                strs[remain].push_back(s[i]);
            } else {
                strs[moder-remain].push_back(s[i]);
            }
            // cout << "===============" << endl;
            // for (auto str:strs) {
            //     cout << str << endl;
            // }
        }
        
        string result("");
        for (string str:strs) {
            // cout << str << endl;
            result += str;
        }
        
        return result;
    }
};