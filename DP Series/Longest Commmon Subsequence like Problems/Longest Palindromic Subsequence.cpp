// link - https://leetcode.com/problems/longest-palindromic-subsequence/
// Time Complexity - O(N*N)
// Space Complexity - O(N*N)

class Solution {
    int lcs(string s,string d){
        int m = s.size();
        int n = d.size();
        int t[m+1][n+1];

        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i==0 || j==0)
                    t[i][j] = 0;
                else if(s[i-1] == d[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else 
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[m][n];

    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};
