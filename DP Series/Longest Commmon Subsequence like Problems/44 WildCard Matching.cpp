// link - https://leetcode.com/problems/wildcard-matching/


// memoisation
bool solve(int i,int j,string s,string p,vector<vector<int>> &dp){
        // base cases
        if(j==p.size() && i==s.size())
            return 1;
        if(i< s.size() && j== p.size())
            return 0;
        if(i==s.size() && j< p.size()){
            for(int k=j;k<p.size();++k)
                if(p[k]!='*')
                    return 0;
            return 1;
        }
    
        if(dp[i][j] != -1)
            return dp[i][j];

        // conditions
        if(p[j]=='?')
            return dp[i][j] = solve(i+1,j+1,s,p,dp);
        else if(p[j]=='*')
            return dp[i][j] = solve(i+1,j,s,p,dp) + solve(i,j+1,s,p,dp);
        else
            return dp[i][j] = (s[i]==p[j]) && solve(i+1,j+1,s,p,dp);

        // return statement
        return dp[i][j];

    }
return solve(0,0,s,p,dp);




// tabulation
bool x(string p,int j){
        for(int k = 1;k<=j;++k){
            if(p[k-1]!='*')
                return 0;
        }
        return 1;
    }
public:
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.size()+1 , vector<int>(p.size()+1,-1));
        // return solve(0,0,s,p,dp);


        int n = s.size();
        int m = p.size();
        bool t[n+1][m+1];


        t[0][0] = 1;
        for(int j=1;j<=m;++j)
            t[0][j] = x(p,j);
        for(int i=1;i<=n;++i)
            t[i][0] = 0;
            
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i-1]==p[j-1] || p[j-1] == '?')
                    t[i][j] = t[i-1][j-1];
                else if(p[j-1] == '*')
                    t[i][j] = t[i-1][j]  || t[i][j-1];
                else
                    t[i][j] = 0;
            }
        }

        return t[n][m];
    }
