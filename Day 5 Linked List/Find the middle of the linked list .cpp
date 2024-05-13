// link - https://leetcode.com/problems/middle-of-the-linked-list/description/
// Time Complexity - O(N/2)
// Space Complexity - O(1)

class Solution {
public:

    ListNode* pro(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* noob = head;
        ListNode* pro = head->next;

        while(pro!=NULL){
            pro = pro->next;
            if(pro){
                pro = pro->next;
            }
            noob = noob->next;
        }
        return noob;
    }
    
    ListNode* middleNode(ListNode* head) {
        return pro(head);
    }
};

