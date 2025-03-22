class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if the list is empty or has only one node left
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Nodes to be swapped
        ListNode* first = head;
        ListNode* second = head->next;

        // Swapping
        first->next = swapPairs(second->next);
        second->next = first;

        // Now the head is the second node
        return second;
    }
};
