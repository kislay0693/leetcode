void _findTarget(TreeNode* root, int k, set<int>& numbers, bool& result){
        if(root == NULL) return;
        _findTarget(root->left, k, numbers, result);
        if(numbers.count(k-root->val)) {
            result = true;
            return;
        }
        numbers.insert(root->val);
        _findTarget(root->right, k, numbers, result);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> numbers;
        bool result = false;
        _findTarget(root, k, numbers, result);
        return result;
    }
