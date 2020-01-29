set<int> val;
    bool _isUnivalTree(TreeNode* root){
        if(root == NULL) return true;
        if(_isUnivalTree(root->left) && _isUnivalTree(root->right) && val.find(root->val) != val.end())
            return true;
        return false;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        val.insert(root->val);
        return _isUnivalTree(root);
    }
