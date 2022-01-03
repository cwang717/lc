using namespace std;

#include <iostream>
#include <string>
#include <math.h>

class Solution {
public:
    static int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
        if (i == s.size()) {
            return 0;
        }
        
        bool positive = true;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') {
                positive = false;
            }
            ++i;
        }
        
        while (i < s.size() && s[i] == '0') {
            ++i;
        }
        
        long value = 0;
        int maxCount = 1;
        long temp = pow(2, 31);
        while (temp > 0) {
            temp /= 10;
            ++maxCount;
        }

        while (s[i] >= '0' && s[i] <= '9') {
            value = value*10 + (int)(s[i]-'0');
            ++i;
            if (--maxCount == 0) {
                value = pow(2, 31);
                break;
            }
        }
        
        int result;
        if (positive) {
            result = value > pow(2, 31) - 1 ? pow(2, 31)-1 : value;
        } else {
            result = value > pow(2, 31) ? -pow(2, 31) : -value;
        }
        
        return result;
    }
};

int main(int argc, char *argv[]) {
    cout << Solution::myAtoi("-912834723320000000000000000") << endl;
}