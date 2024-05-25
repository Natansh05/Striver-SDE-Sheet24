// link - geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
// Time Complexity - O(N)
// Space Complexity - O(N/2) --- Recursion Stack Space

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int size){
        if(s.size() == (size + 1)/2){
            s.pop();
            return;
        }
        
        int top = s.top();
        s.pop();
        deleteMid(s,size);
        s.push(top);
        
        return;
    }
};
