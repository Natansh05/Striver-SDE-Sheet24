// link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode *slow = dummy,*fast = dummy;

        for(int i=0;i<n;++i){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        head = dummy->next;

        delete(dummy);
        return head;
    }
};
