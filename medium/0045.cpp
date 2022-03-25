class Solution {
public:
    int jump(vector<int>& nums) {
        unordered_map<int, bool> visited;
        queue<int> to_visit; 
    
        if (nums.size()==1) {
            return 0;
        }
        
        int current_count = 1;
        int next_count = 0;
        int current_step = 1;
        to_visit.push(0);
        bool done = false;
        while (! to_visit.empty() && !done) {
            if (current_count == 0) {
                current_step++;
                current_count = next_count;
                next_count = 0;
            }
            int front = to_visit.front();
            int max_steps = nums[front];
            for (int i=1; i<max_steps+1; ++i) {
                int newElem = front + i;
                if (visited.find(newElem) == visited.end()) {
                    visited[newElem] = true;
                    to_visit.push(newElem);
                    next_count++;
                    if (newElem >= nums.size()-1) {done = true;}
                    //cout << front<< ":" << newElem << endl;
                }
            }
            to_visit.pop();
            current_count--;
        }
        
        return current_step;
    }
};