class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize a dummy node to build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        // Iterate through both lists until both are exhausted
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the current values, defaulting to 0 if the list is exhausted
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum and the new carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;

            // Create a new node with the digit value and move the pointer
            current->next = new ListNode(sum % 10);
            current = current->next;

            // Move to the next nodes in the input lists if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // The result list is next to the dummy node
        return dummy->next;
    }
};
