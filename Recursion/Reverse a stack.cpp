// link - https://www.geeksforgeeks.org/problems/reverse-a-stack/1
// Time Complexity - O(N^2)
// Space Complexity - O(1)

class Solution{
    void solve(stack<int> &s,int el){
        if(s.empty()){
            s.push(el);
            return;
        }
        int top = s.top();
        s.pop();
        solve(s,el);
        s.push(top);
    }
public:
    void Reverse(stack<int> &s){
        if(s.empty())
            return;
        int top = s.top();
        s.pop();
        Reverse(s);
        solve(s,top);
        return;
    }
};
