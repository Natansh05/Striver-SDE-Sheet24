// link - geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution{
    public:
    
    int longestCommonSubstr (string s, string s2, int n, int m)
    {
        int t[n+1][m+1];
        int maxi = 0;
        
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if(i==0 || j==0)
                    t[i][j] = 0;
                else if(s[i-1]==s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    maxi = max(maxi,t[i][j]);
                }
                else{
                    t[i][j] = 0;
                }
            }
        }
        
        return maxi;
    }
};
