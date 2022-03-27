class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int nx = 0, no = 0;
        
        for (auto row:board) {
            for (auto c:row) {
                if (c=='X') nx++;
                if (c=='O') no++;
            }
        }
        
        bool Xwin = checkWin(board, 'X'), Owin = checkWin(board, 'O');
        if (Xwin && nx==no+1 && !Owin) return true;
        if (Owin && nx==no && !Xwin) return true;
        //draw
        if (!Xwin && !Owin && nx+no==9) return true;
        //pending
        if (!Xwin && !Owin && (nx==no || nx==no+1)) return true;
        
        return false;
    }

private:
    bool checkWin(const vector<string> &board, char c) {
        bool result = false;
        for (int i = 0; i<3; ++i) {
            result = result || ThreeFromPosition(0, i, c, board);
        }
        for (int i:{1,2}) {
            result = result || ThreeFromPosition(i, 0, c, board);
        }
        
        return result;
    }
    
    bool ThreeFromPosition(int i, int j, char c, const vector<string> &board) {
        if (i==0) {
            if (board[0][0]==c && board[1][1]==c && board[2][2]==c) return true;
            if (board[0][2]==c && board[1][1]==c && board[2][0]==c) return true;
            if (board[0][j]==c && board[1][j]==c && board[2][j]==c) return true;
            
        }
        if (j==0) {
            if (board[i][0]==c && board[i][1]==c && board[i][2]==c) return true;
        }
        return false;
    }
};