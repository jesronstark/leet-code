 
#include <vector>
#include <queue>
 

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Comparator for the priority queue (min-heap)
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> minHeap(comp);

        // Initialize the heap with the head of each list
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        // Dummy node to start the merged list
        ListNode dummy(0);
        ListNode* current = &dummy;

        // Extract the smallest element from the heap and add to the merged list
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            current->next = smallest;
            current = current->next;

            // If there is a next node, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
