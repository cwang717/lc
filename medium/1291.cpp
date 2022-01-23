using namespace std;

#include <vector>

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int lowLength = 0, highLength = 0;
        int tempLow = low, tempHigh = high;
        while (tempLow) {
            ++lowLength;
            tempLow /= 10;
        }
        while (tempHigh) {
            ++highLength;
            tempHigh /=10;
        }
        
        int base = 0, plus = 0;
        for (int i = 1; i<lowLength; ++i) {
            base = base * 10 + i;
            plus = plus * 10 + 1;
        }
        for (int currentDigits = lowLength; currentDigits<max(highLength, 10); ++currentDigits) {
            base = base * 10 + currentDigits;
            plus = plus * 10 + 1;
            for (int i=0; i<10-currentDigits; ++i) {
                int candidate = base + i*plus;
                if (candidate > high) {
                    break;
                }
                if (candidate < low) {
                    continue;
                }
                result.push_back(candidate);
            }
        }
        
        return result;
    }
};