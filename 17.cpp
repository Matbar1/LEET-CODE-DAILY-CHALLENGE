class Solution {
public:
   
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    std::stack<int> stack1, stack2;
    
    // Push values of l1 into stack1
    while (l1) {
        stack1.push(l1->val);
        l1 = l1->next;
    }
    
    // Push values of l2 into stack2
    while (l2) {
        stack2.push(l2->val);
        l2 = l2->next;
    }
    
    int carry = 0;
    ListNode* result = nullptr;
    
    // Perform addition digit by digit
    while (!stack1.empty() || !stack2.empty() || carry != 0) {
        int sum = carry;
        
        if (!stack1.empty()) {
            sum += stack1.top();
            stack1.pop();
        }
        
        if (!stack2.empty()) {
            sum += stack2.top();
            stack2.pop();
        }
        
        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);
        
        // Update the result
        newNode->next = result;
        result = newNode;
    }
    
    return result;
}
};