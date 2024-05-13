// link - https://leetcode.com/problems/linked-list-cycle/description/
// Time Complexity - O(N)
// Space Complexity - O(1)

// Floyd's Loop Detection Algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        if (head==nullptr || head->next==nullptr)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
    
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    }
};
