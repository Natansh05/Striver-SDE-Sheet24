// link - https://leetcode.com/problems/target-sum/description/
// Time Complexity - O(N*Sum)
// Space Complexity - O(N*Sum)

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
                    t[i][j] = t[i-1][j-ans[i-1]] + t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j] ;
            }
        }
        
        return t[n][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int diff) {
        ios_base::sync_with_stdio(0);
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;++i)
            sum+=nums[i];
        if(sum < diff|| (sum + diff) < 0 || (sum + diff)&1)
            return 0;
        return solve(nums,(sum+diff)/2);
    }
};
