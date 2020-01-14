    int sum = 0;
    bool carry = false;
    void _addTwoNumbers(ListNode* l1, ListNode* l2){
        if(l1 == NULL && l2 == NULL)
            return;
        _addTwoNumbers(l1->next,l2->next);
        sum += l1->val + l2->val;
        carry = sum >= 10 ? true : false;
        l1->val = sum%10;
        sum /= 10;
        return;
    }
    int getListLength(ListNode* l1){
        int len = 0;
        while(l1){
            l1 = l1->next;
            len++;
        }
        return len;
    }
    void computeSum(ListNode* l1, ListNode* temp){
        
        if(l1 == NULL || l1 == temp) return;
        computeSum(l1->next,temp);
        l1->val = carry ? l1->val+1 : l1->val;
        carry = l1->val >= 10 ? true: false;
        l1->val %= 10;
        return;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* temp;
        int len1 = getListLength(l1);
        int len2 = getListLength(l2);
        int lenDiff = abs(len1-len2);
        int count = 0;
        if(len1 > len2){
            while(ptr1 && count < lenDiff){
                ptr1 = ptr1->next;
                count++;
            }
            temp = ptr1;
            _addTwoNumbers(ptr1, ptr2);
        }else if(len2 > len1){
            while(ptr2 && count < lenDiff){
                ptr2 = ptr2->next;
                count++;
            }
            temp = ptr2;
            _addTwoNumbers(ptr2, ptr1);
        }else
            _addTwoNumbers(ptr1, ptr2);
        
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if(carry == true){
            if(len1 > len2)
                computeSum(p1, temp);
            else if(len2 > len1)
                computeSum(p2, temp);
        
        }
        if(carry == true){
            
            ListNode* head = new ListNode(1);
            head->next = len1>=len2? l1: l2;
            return head;
        }
        return len1>=len2 ? l1 : l2;
    }
