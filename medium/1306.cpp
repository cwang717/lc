class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // cout << start << endl;
        if (start < 0 || start >= arr.size()) {
            return false;
        }
        if (arr[start] == 0) {
            return true;
        } 
        if (arr[start] < 0) {
            return false;
        }
        int step = arr[start];
        arr[start] = -1;
        bool result = canReach(arr, start-step) || canReach(arr, start+step);
        
        return result;
    }
};