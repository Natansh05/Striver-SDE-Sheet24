// link - https://leetcode.com/problems/reverse-linked-list/description/



// -----------------------------ITERATIVE APPROACH-----------------------------------
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(nxt){
            nxt = curr->next;
            curr->next =prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
};



// -----------------------------RECURSIVE APPROACH-----------------------------------
// Time Complexity - O(N)
// Space Complexity - O(N) --Recursive Stack Space

void reverse(ListNode* &head , ListNode* curr , ListNode* prev){
        if(curr==NULL){
            head = prev;
            return;
        }

        reverse(head,curr->next,curr);
        curr->next = prev;
    }

// -----------------------------RECURSIVE APPROACH-----------------------------------
// Time Complexity - O(N)
// Space Complexity - O(1)

ListNode* reverse1(ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* chota_head = reverse1(head->next);
        head->next->next = head;
        head->next = NULL;

        return chota_head;
    }



