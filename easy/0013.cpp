class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict{{'I', 1},
                                      {'V', 5}, 
                                      {'X', 10}, 
                                      {'L', 50}, 
                                      {'C', 100}, 
                                      {'D', 500}, 
                                      {'M', 1000}};
        
        int result = 0;
        for (int i = s.size()-1; i>=0; --i) {
            if (i<s.size()-1 && ((s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')) ||
                                 (s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')) ||
                                 (s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')))) {
                result -= dict[s[i]];
                continue;
            }
            result += dict[s[i]];
            // cout << result << endl;
        }
        
        return result;
    }
};