class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3, vector<int>(3, -1));
        
        for (int i=0; i<moves.size(); ++i) {
            // A:0, B:1;
            grid[moves[i][0]][moves[i][1]] = i%2;
        }
        
        bool Awin = false, Bwin = false;
        for (int i=0; i<3; ++i) {
            if (winAtPosition(grid, 0, i)) {
                if (grid[0][i] == 0) {
                    Awin = true;
                } else {
                    Bwin = true;
                }
            }
        }
        for (int i = 1; i<3; ++i) {
            if (winAtPosition(grid, i, 0)) {
                if (grid[i][0] == 0) {
                    Awin = true;
                } else {
                    Bwin = true;
                }
            }
        }
        
        // cout << Awin << ", " << Bwin << endl;
        
        if (Awin || Bwin) {
            if (Awin && Bwin) {
                return "Draw";
            } else {
                return Awin ? "A" : "B";
            }
        } else {
            return moves.size()==9 ? "Draw" : "Pending";
        }
        
        
    }
    
private: 
    bool winAtPosition(const vector<vector<int>> &grid, int x, int y) {
        int mark = grid[x][y];
        if (mark==-1) return false;
        if (x == 0) {
            if (grid[x+1][y]==mark && grid[x+2][y]==mark) return true;
            if (y==0 && grid[1][1]==mark && grid[2][2]==mark) return true;
            if (y==2 && grid[1][1]==mark && grid[2][0]==mark) return true;
        }
        if (y == 0) {
            if (grid[x][y+1]==mark && grid[x][y+2]==mark) return true;
        }
        
        return false;
    }
};