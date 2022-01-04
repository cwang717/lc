using namespace std;

#include <stack>

class Solution {
public:
    int bitwiseComplement(int n) {
        if (!n) {
            return 1;
        }
        stack<int> s;
        while (n > 0) {
            s.push(n%2);
            n = n >> 1;
        }
        
        int result = 0;
        while (!s.empty()) {
            result = result * 2 + (s.top()^1);
            s.pop();
        }
        
        return result;
    }
};