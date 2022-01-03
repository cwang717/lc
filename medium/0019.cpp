

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode prehead = ListNode(0, head);
        ListNode *nPrevious = &prehead;
        ListNode *current = head;
        while (current) {
            if (n>0) {
                --n;
            } else {
                nPrevious = nPrevious -> next;
            }
            current = current->next;
        }
        nPrevious->next = nPrevious->next->next;
        return prehead.next;
    }
};