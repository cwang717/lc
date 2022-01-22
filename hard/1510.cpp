using namespace std;

#include <vector>
#include <math.h>

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> record(n);
        int currentRoot = 1;
        
        for (int i = 0; i<n; ++i) {
            int num = i+1;
            if (num == currentRoot*currentRoot) {
                record[i] = true;
                ++currentRoot;
            } else {
                record[i] = false;
                for (int tempRoot = 1; tempRoot < currentRoot; ++tempRoot) {
                    if (!record[num-pow(tempRoot, 2)-1]) {
                        record[i] = true;
                        break;
                    }
                }
            }
        }
        
        return record[n-1];
    }
};