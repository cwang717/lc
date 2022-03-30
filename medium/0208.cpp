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
    
    bool search(string word) {
        TrieNode* current = root;
        for (char c:word) {
            if (current->children.find(c) == current->children.end()) return false;
            current = current->children[c];
        }
        return current->children.find('E') != current->children.end();
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c:prefix) {
            if (current->children.find(c) == current->children.end()) return false;
            current = current->children[c];
        }
        return true;
    }
    
private: 
    TrieNode* insertChar(TrieNode* current, char c) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        return current->children[c];
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */