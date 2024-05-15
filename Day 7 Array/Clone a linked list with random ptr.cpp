// link - https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// ---------------------------APPROACH 1--------------------------------------
// Time Complexity - O(N)
// Space Complexity - O(1)


class Solution
{
    private:
    void insert(Node* &head,Node* &tail,int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        return;
    }
    public:
    Node *copyList(Node *head){
        Node* temp = head;
        
        map<Node*,Node*> mp;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        while(temp){
            insert(cloneHead,cloneTail,temp->data);
            mp[temp] = cloneTail;
            temp = temp->next;
        }
        
        temp = head;
        Node* temp2 = cloneHead;
        
        while(temp && temp2){
            temp2->arb = mp[temp->arb];
            temp2 = temp2->next;
            temp = temp->next;
        }
        
        return cloneHead;
    }

};

