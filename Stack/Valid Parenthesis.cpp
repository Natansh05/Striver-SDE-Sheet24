// link - https://leetcode.com/problems/valid-parentheses/description/
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(0);
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty())
                    return 0;
                else if(st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]=='}'){
                if(st.empty())
                    return 0;
                else if(st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]==']'){
                if(st.empty())
                    return 0;
                else if(st.top()=='[')
                    st.pop();
                else
                    return false;
            }   
        }
        if(st.empty())
            return 1;
        else
            return 0;
    }
};
