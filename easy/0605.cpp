using namespace std;

#include "vector"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        int i = 0;
        bool previous = false;
        while (n>0 && i < flowerbed.size()) {
            if (previous) {
                previous = (flowerbed[i]==1);
                ++i;
            } else {
                if (flowerbed[i] == 1) {
                    ++i;
                    previous = true;
                } else {
                    if (i+1 == flowerbed.size()) {
                        --n;
                        ++i;
                    } else {
                        if (flowerbed[i+1] == 1) {
                            i+=2;
                            previous=true;
                        } else {
                            --n;
                            i+=2;
                            previous=false;
                        }
                    }
                }
            }

        }
        return n==0;
    }
};