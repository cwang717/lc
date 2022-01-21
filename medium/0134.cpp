using namespace std;

#include <vector>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minSum = 0, currentSum = 0, minPos = -1;
        
        for (int i = 0; i < gas.size(); ++i) {
            currentSum += gas[i] - cost[i];
            if (currentSum < minSum) {
                minPos = i;
                minSum = currentSum;
            }
        }
        
        if (currentSum < 0) {
            return -1;
        } else {
            return (minPos+1)%gas.size();
        }
    }
};