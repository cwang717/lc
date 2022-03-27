class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> preSums(m+1, vector<int>(n, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                preSums[i+1][j] = preSums[i][j] + matrix[i][j];
            }
        }
        // print2DVector(preSums);
        // cout << maxSumSubarray(vector<int>{2, 2, -1}, 3) <<endl;
        int result = INT_MIN;
        for (int i=0; i<m; ++i) {
            for (int j=i+1; j<m+1; ++j) {
                vector<int> arr(n, 0);
                for (int k=0; k<n; ++k) {
                    arr[k] = preSums[j][k] - preSums[i][k];
                }
                
                //find max sum ( <k ) of subarray in arr
                int arrMax = maxSumSubarray(arr, k);
                // if (result<arrMax) cout<<i<<", "<<j<<", "<<arrMax<<endl;
                result = max(result, arrMax);
                
            }
        }
        
        return result;
    }
    
private:
    int maxSumSubarray(const vector<int> &arr, int k) {
        int n = arr.size();
        
        int result=INT_MIN;
        
        set<int> preSums;
        preSums.insert(0);
        int currentSum = 0;
        for (int i=0; i<n; ++i) {
            currentSum += arr[i];
            // currentSum-x<=k
            set<int>::iterator it=preSums.lower_bound(currentSum-k);
            if (it!=preSums.end()) result = max(result, currentSum-*it);
            // cout << result <<endl;
            preSums.insert(currentSum);
        }
        
        return result;
    }
    void print2DVector(const vector<vector<int>> &v) {
        for (auto r:v) {
            for (auto e:r) {
                cout << e << ", ";
            }
            cout << endl;
        }
        return;
    }
    void printVector(const vector<int> &v) {
        for (auto e:v) {
            cout << e << ", ";
        }
        cout << endl;
        return;
    }  
};