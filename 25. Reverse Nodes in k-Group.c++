class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        // Dummy node initialization
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Check if there are at least k nodes left to reverse
            ListNode* kthNode = prevGroupEnd;
            for (int i = 0; i < k && kthNode != nullptr; ++i) {
                kthNode = kthNode->next;
            }
            if (kthNode == nullptr) break;

            // Reverse k nodes
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kthNode->next;
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            for (int i = 0; i < k; ++i) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous group to the current reversed group
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
