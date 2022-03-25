//recursion

class Solution {
public:
    int rob(TreeNode* root) {
        return rob_(root, false);
    }
private:
    int rob_(TreeNode* root, bool robParent) {
        if (root == nullptr) {return 0;}
        if (robParent) {
            return rob_(root->left, false) + rob_(root->right, false);
        } else {
            return max(rob_(root->left, false) + rob_(root->right, false),
                       rob_(root->left, true) + rob_(root->right, true) + root->val);
        }
    }
};

// dp + recursion
class Solution {
public:
    int rob(TreeNode* root) {
        //pair: rob parent, not rob parent
        unordered_map<TreeNode*, pair<int, int>> visited;
        return  rob_(root, visited).second;
    }
private:
    pair<int, int> rob_(TreeNode* root, unordered_map<TreeNode*, pair<int, int>> &visited) {
        if (visited.find(root) != visited.end()) {return visited[root];}
        if (root == nullptr) {
            visited[root] = make_pair(0, 0);
            return visited[root];
        }
        pair<int, int> left = rob_(root->left, visited);
        pair<int, int> right = rob_(root->right, visited);
        pair<int, int> rootPair = make_pair(left.second + right.second, 
                                              max(left.second+right.second, 
                                                  root->val+left.first+right.first));
        visited[root] = rootPair;
        return rootPair;
    }
};