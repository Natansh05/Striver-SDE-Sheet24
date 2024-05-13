// link - https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
    ListNode* reverseK(ListNode* head,int k){  
        if(head==NULL || head->next ==NULL)
            return head;
        
        ListNode* check = head;

        for(int i = 0; i < k; i++){
            if(check == nullptr) return head;
            check = check->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        
        int cnt = k;
        while(curr && cnt--){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseK(curr,k);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next ==NULL)
            return head;
        
        return reverseK(head,k);
    }
};
