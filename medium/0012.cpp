class Solution {
public:
    string intToRoman(int num) {
        vector<vector<string>> dict(10, vector<string>(4, ""));
        dict[1] = vector<string>{"I", "X", "C", "M"};
        dict[5] = vector<string>{"V", "L", "D"};
        //2 and 3
        for (int i=0; i<4; ++i) {
            dict[2][i] += dict[1][i] + dict[1][i];
            dict[3][i] += dict[2][i] + dict[1][i];
            if (i<3) {
                dict[4][i] += dict[1][i] + dict[5][i];
                dict[6][i] += dict[5][i] + dict[1][i];
                dict[7][i] += dict[6][i] + dict[1][i];
                dict[8][i] += dict[7][i] + dict[1][i];
                dict[9][i] += dict[1][i] + dict[1][i+1];
            }
            
        }
        
        string result("");
        int k = 0;
        while (num) {
            int remain = num%10;
            result = dict[remain][k] + result;
            num /= 10;
            ++k;
        }
        
        return result;
    }
};