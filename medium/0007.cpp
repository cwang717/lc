class Solution {
public:
    int reverse(int x) {
        bool negative = (x<0);
        int result = 0;
        while (x!=0) {
            if ((INT_MAX/10 < result) || (INT_MIN/10 > result)) return 0; 
            result = result*10 + x%10;
            x /= 10;
        }
        
        return result;
    }
};