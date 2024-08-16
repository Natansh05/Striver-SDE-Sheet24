// Time Complexity - O(n*m)
// Space Complexity - O(n*m)


class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans = "";
        int i = n,j = m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                --i;
                --j;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                --i;
            else
                --j;
        }
        
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        return dp[n][m];
        
    }
};
