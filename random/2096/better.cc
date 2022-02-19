/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findNode(TreeNode* current, int target, vector<char>& path) {
        bool ret = false;
        
        //termination condition
        if (current->val == target) {
            return true;
        }
        
        //recursively search left node
        if (current->left != nullptr) {
            path.push_back('L');
            ret |= findNode(current->left, target, path);
            if (ret) return ret;
            path.pop_back();
        }
        //recursively search right node
        if (current->right != nullptr) {
            path.push_back('R');
            ret |= findNode(current->right, target, path);
            if (ret) return ret;
            path.pop_back();
        }
        return ret;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> startPath, destPath;
        
        findNode(root, startValue, startPath);
        findNode(root, destValue, destPath);
        int index = 0;
        //reduce common ancestors
        while (index < startPath.size() && index < destPath.size() && startPath[index] == destPath[index]) index++;
        string ans = "";
        for (int i = index; i < startPath.size(); i++) {
            ans += "U";
        }
        for (int i= index; i < destPath.size(); i++) {
            ans += destPath[i];
        }
        return ans;
    }
};
/*
1. Finding Lowest Common Ancestor for both node
2. Find start -> LCA -> dest path
*/