// link - https://leetcode.com/problems/generate-parentheses/
// Time Complexity - O(2^N-1)
// Space Complexity - O(2^N-1 + N)

class Solution {
    vector<string> ans;
    void solve(string s,int open,int close){
        if(open == 0 && close ==0){
            ans.push_back(s);
            return;
        }


        if(open > 0){
            string op1 = s;
            op1.push_back('(');
            solve(op1,open-1,close);
        }

        if(close>0 && close>open){
            string op2 = s;
            op2.push_back(')');
            solve(op2,open,close-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(0);
        string s = "";
        int open = n,close = n;
        solve(s,open,close);
        return ans;

    }
};

