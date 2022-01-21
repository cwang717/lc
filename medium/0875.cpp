using namespace std;

#include <vector>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = 0;
        for (int p:piles) {
            maxBananas = max(maxBananas, p);
        }
        
        int low = 1, high = maxBananas, mid = -1;
        while (low < high) {
            mid = (low + high)/2;
            int hours = 0;
            for (int p:piles) {
                hours += (p+mid-1)/mid;
            }
            
            if (hours > h) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};