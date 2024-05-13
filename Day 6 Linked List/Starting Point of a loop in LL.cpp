// link - https://leetcode.com/problems/linked-list-cycle-ii/description/
// Time Complexity - O(N)
// Space Complexity - O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;

        while(slow!=fast){
            if(fast==NULL || fast->next==NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};
