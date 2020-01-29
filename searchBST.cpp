 void _searchBST(TreeNode* root, int val, TreeNode*& result){
        
        if(root == NULL) return;
        if(root->val == val) {
            result = root;
            return;
        }
        if(root->val > val) _searchBST(root->left, val, result);
        else
            _searchBST(root->right, val, result);
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* result = NULL;
        
        _searchBST(root, val, result);
        return result;
    }
