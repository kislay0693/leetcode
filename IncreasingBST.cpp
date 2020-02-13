 TreeNode* current;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode(0);
        current = ans;
        inorder(root, current);
        return ans->right;
    }
    void inorder(TreeNode* root, TreeNode*& current){
        if(root == NULL) return;
        inorder(root->left, current);
        root->left = NULL;
        current->right = root;
        current = current->right;
        inorder(root->right,current);
    }
