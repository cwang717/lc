class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // state: i, j, r
        // (0, 0) -> (m-1, n-1)
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> max_r(m, vector<int>(n, -1));
        
        queue<vector<int>> q;
        q.push({0, 0, k, 0});
        
        while(!q.empty()) {
            vector<int> current = q.front();
            q.pop();
            
            int x = current[0];
            int y = current[1];
            int r = current[2];
            int dist = current[3];
            
            //outside the grid;
            if (x<0 || x>=m || y<0 || y>=n) {
                continue;
            }
            //obstacle
            if (grid[x][y] == 1) {
                if (r==0) {
                    continue;
                } else {
                    r--;
                }
            }
            //
            if (r>max_r[x][y]) {
                max_r[x][y] = r;
            } else {
                continue;
            }
            
            // cout << x << ", " << y << ", " << r << ", " << dist << endl;
            // arrive
            if (x==m-1 && y==n-1) {
                return dist;
            }
            
            q.push({x, y+1, r, dist+1});
            q.push({x, y-1, r, dist+1});
            q.push({x+1, y, r, dist+1});
            q.push({x-1, y, r, dist+1});
        }
        
        return -1;
        
    }
};