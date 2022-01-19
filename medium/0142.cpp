
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                int loopSize = 0;
                do {
                    fast = fast->next->next;
                    slow = slow->next;
                    ++loopSize;
                } while (slow != fast);
                ListNode *result=head;
                for (int i = 0; i < loopSize; ++i) {
                    head = head->next;
                }
                while (result != head) {
                    result = result->next;
                    head = head->next;
                }
                return result;
            }
        }
        
        return NULL;
    }
};