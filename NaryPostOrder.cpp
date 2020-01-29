vector<int> postorder(Node* root) {
        vector<int> result;
        list<Node*> stack_list;
        
        if(root == NULL) return result;
        stack_list.push_back(root);
        
        while(!stack_list.empty()){
            Node* temp = stack_list.back();
            stack_list.pop_back();
            result.insert(result.begin(), temp->val);
            for(Node* node: temp->children){
                stack_list.push_back(node);
            }
        }
        return result;
    }
