 bool _isValidBST(TreeNode* root, TreeNode *&prev){
        if(root){
          if(!_isValidBST(root->left, prev)) return false;
          if(prev != NULL && root->val <= prev->val) return false;
          prev = root;
          return _isValidBST(root->right, prev);
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return _isValidBST(root, prev);
    }
