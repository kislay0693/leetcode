 void _rangeSumBST(TreeNode* root, int l, int r, int& sum){
        if(root == NULL ) return;
        _rangeSumBST(root->left, l, r, sum);
        if(root->val >=l && root->val <= r) sum += root->val;
        _rangeSumBST(root->right, l, r, sum);
        
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        _rangeSumBST(root, L, R, sum);
        return sum;
    }
