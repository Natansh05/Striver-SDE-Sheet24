// link - https://leetcode.com/problems/palindrome-partitioning-ii/
// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution {
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--])
                return 0;
        }
        return 1;
    }

    int solve(int i,int j,string &s,vector<vector<int>> &t){
        if(i>=j)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        if(isPalindrome(s,i,j))
            return 0;
        
        int ans = INT_MAX;  
        for(int k=i;k<j;++k){
            if(isPalindrome(s,i,k)){
                int temp = 1 + solve(k+1,j,s,t);
                ans = min(ans,temp);
            }
        }
        return t[i][j] = ans;
    }


public:
    int minCut(string s) {
        ios_base::sync_with_stdio(0);
        int n = s.size();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        return solve(0,s.size()-1,s,t);
    }
};
