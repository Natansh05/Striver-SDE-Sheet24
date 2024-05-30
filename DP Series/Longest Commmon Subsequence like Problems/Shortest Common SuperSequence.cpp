// link - https://leetcode.com/problems/shortest-common-supersequence/description/
// Time Complexity - O(N*N)
// Space Complexity - O(N*N)

class Solution {
public:
    string shortestCommonSupersequence(string s, string d) {
        ios_base::sync_with_stdio(0);
        int n = s.size();
        int m = d.size();
        int t[n+1][m+1];
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if(i==0 || j==0)
                    t[i][j] = 0;
                else if(s[i-1]==d[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        
        string ans  = "";
        int i = n, j = m;
        while(i>0 && j>0){
            if(s[i-1]==d[j-1]){
                ans += s[i-1];
                i--;
                j--;
            }
            else if(t[i-1][j] > t[i][j-1]){
                ans += s[i-1];
                --i;
            }
            else{
                ans += d[j-1];
                --j;
            }
        }

        while(i>0){
            ans += s[i-1];
            --i;
        }

        while(j>0){
            ans+=d[j-1];
            --j;
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};
