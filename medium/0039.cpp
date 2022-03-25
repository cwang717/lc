class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> current{};
        vector<vector<int>> result;
        combination(candidates, 0, target, current, result);
        
        return result;
    }
    
    void combination(vector<int>& candidates, int lb, int target, vector<int>& current, vector<vector<int>>& result) {
        //cout << "lb: " << lb << "; target: " << target << endl;
        if (target==0) {
            result.push_back(current);
            return;
        }
        if (target < 0) {
            return;
        }
        
        for (int i=lb; i<candidates.size(); ++i) {
            current.push_back(candidates[i]);
            combination(candidates, i, target-candidates[i], current, result);
            current.pop_back();
        }
        
        return;
        
    }
};