// link - geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Time Complexity - O(K^2logK)
// Space Complexity - O(K^2)

struct cmp{
    bool operator()(Node* n1,Node* n2){
        return n1->data > n2->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *nums[], int k){
        priority_queue<Node*,vector<Node*>,cmp> pq;
        for(int i=0;i<k;++i){
            if(nums[i])
                pq.push(nums[i]);
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        // if(pq.empty())
        //     return NULL;
        
        while(!pq.empty()){
            Node* mini = pq.top();
            pq.pop();
            
            tail->next = mini;
            tail = tail->next;
            
            if(mini->next)
                pq.push(mini->next);
        }
        return dummy->next;
    }
};
