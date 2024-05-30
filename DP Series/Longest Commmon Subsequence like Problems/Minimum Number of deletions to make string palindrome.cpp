// link - https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
// Time Complexity - O(N*N)
// Space Complexity - O(N*N)


int minDeletions(string s, int n) {
    string d = s;
    reverse(d.begin(),d.end());
    
    int t[n+1][n+1];
    
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            if(i==0 || j==0)
                t[i][j] = 0;
            else if(s[i-1]==d[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    
    int lcs = t[n][n];
    
    return n-lcs;
} 
