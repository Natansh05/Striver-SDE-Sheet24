// link - https://leetcode.com/problems/longest-common-subsequence/
// Time Complexity - O(N*M)
// Space Com[plexity - O(N*M)

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        ios_base::sync_with_stdio(false);
        int m = s.length();
        int n = t.length();

        int arr[m+1][n+1];
        
        for(int i=0;i<m+1;++i){
            for(int j=0;j<n+1;++j){
                if(i==0||j==0)
                    arr[i][j] = 0;
                else if(s[i-1]==t[j-1])
                    arr[i][j] = 1 + arr[i-1][j-1];
                else
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
        return arr[m][n];
    }
};
