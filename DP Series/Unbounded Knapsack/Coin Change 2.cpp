// link - https://leetcode.com/problems/coin-change-ii/
// Time Complexity - O(N*Amount)
// Space Complexity - O(N*Amount)

class Solution {
    int solve(vector<int> ans,int target){
        int n = ans.size();
        int t[n+1][target+1];
        
        // initialization
        for(int i=0;i<=n;++i){
            for(int j=0;j<=target;++j){
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
            }
        }
        
        
        // bottom up approach
        for(int i=1;i<=n;++i){
            for(int j=0;j<=target;++j){
                // YAHA PE LOOP KE ANDAR J=0 TABHI INCLUDE KARNA PADEGA JAB ELEMENT ME KOI NEGATIVE YA ZERO KA ELEMENT HO
                // ELSE TARGET = 0 KA ALWAYS EK EMPTY SUBARRAY HI ANS HONA CHAIIYE 
                // INCASE 0 OR NEGATIVE ELEMENT EXISTS , THERE MAYBE BE MULTIPLE KIND OF SUBSETS WITH SUM 0
                if(ans[i-1]<=j){
                    t[i][j] = (t[i][j-ans[i-1]] + t[i-1][j]);
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][target];
    }
public:
    int change(int amount, vector<int>& coins) {
        return solve(coins,amount);
    }
};
