int sum = 0;
    int getTotalSum(TreeNode* root){
        if(!root) return 0;
        sum += root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
        return sum;
    }
    void inorderTraversal(TreeNode* root, int& sum){
        if(root == NULL) return;
        inorderTraversal(root->left, sum);
        int temp = root->val;
        root->val = sum;
        sum -= temp;
        inorderTraversal(root->right, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = getTotalSum(root);
        inorderTraversal(root,sum);
        return root;
    }
