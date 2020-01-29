vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == NULL) return result;
        stack<vector<Node*>> st;
        
        result.push_back(root->val);
        if(root->children.size() > 0)
          st.push(root->children);
        
        while(!st.empty()){
            
            vector<Node*> child = st.top();
            st.pop();
            Node* temp = child.front();
            result.push_back(temp->val);
            child.erase(child.begin());
            if(child.size() > 0) st.push(child);
            if(temp->children.size() > 0) st.push(temp->children);
        }
        
        return result;
        
    }
