using namespace std;

#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    static int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1) {
            return 1;
        }
        unordered_map<int, int> trustCount, trustCount2;
        for (vector<int> &pair:trust) {
            trustCount[pair[1]]++;
            trustCount2[pair[0]]++;
        }
        
        int judge = -1;
        for (auto temp:trustCount) {
            if (temp.second == n-1) { 
                judge = temp.first;
            }
        }
        
        if (judge != -1 && trustCount2.find(judge) == trustCount2.end()) {
            return judge;
        } else {
            return -1;
        }
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> trust;
    trust.push_back(vector<int>{1, 2});
    cout << Solution::findJudge(2, trust) << endl;
}