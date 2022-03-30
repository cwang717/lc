class TrieNode {
public:
    TrieNode() {
        children = unordered_map<char, TrieNode*>();
    }
    unordered_map<char, TrieNode*> children;
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for (char c:word) {
            current = insertChar(current, c);
        }
        //'E' for end;
        insertChar(current, 'E');
    }
    
private: 
    TrieNode* insertChar(TrieNode* current, char c) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        return current->children[c];
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t = Trie();
        for (auto w:words) {
            t.insert(w);
        }
        
        int m = board.size();
        int n = board[0].size();
        string current_s("");
        set<string> result;
        //dfs
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                dfs(t.root, board, i, j, result, current_s);
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }
    
    void dfs(TrieNode* current, vector<vector<char>>& board, int i, int j, set<string> &result, string &current_s){
        //found word
        if (current->children.find('E') != current->children.end()) {
            result.insert(current_s);
            current->children.erase('E');
        }
        // invalid position
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        // visited
        if (board[i][j] == 'V') return;
        
        char c = board[i][j];
        if (current->children.find(c) == current->children.end()) return;
        board[i][j] = 'V';
        current_s.push_back(c);
        dfs(current->children[c], board, i+1, j, result, current_s);
        dfs(current->children[c], board, i-1, j, result, current_s);
        dfs(current->children[c], board, i, j-1, result, current_s);
        dfs(current->children[c], board, i, j+1, result, current_s);
        if (current->children[c]->children.size() == 0) {current->children.erase(c);}
        current_s.pop_back();
        board[i][j] = c;
    }
};