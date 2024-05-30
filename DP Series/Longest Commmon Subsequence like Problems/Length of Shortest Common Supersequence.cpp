// link - https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// Time Complexity - O(N*M)
// Space Complexity - O(M*N)


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        // length of shortest common supersequence = x + y - lcs(x,y);
        
        
        int t[m+1][n+1];
        
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i==0 || j==0 )
                    t[i][j] = 0;
                else if(x[i-1]==y[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
        
        int lcs = t[m][n];
        return m + n - lcs;
    }
};
