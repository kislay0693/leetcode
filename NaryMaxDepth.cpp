 int maxDepth(Node* root) {
       
        if(root == NULL) return 0;
        else if(root->children.empty()) return 1;
        else{
            vector<int> heights;
            for(auto c: root->children)
                heights.push_back(maxDepth(c));
            auto it = max_element(std::begin(heights), std::end(heights));
            return *it + 1;
        }
