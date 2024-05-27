// link - https://leetcode.com/problems/partition-equal-subset-sum/description/
// Time Complexity - O(N*Sum/2)
// Space Complexity - O(N*Sum/2)

class Solution {
    bool solve(vector<int> &ans,int target){
        int n = ans.size();
        bool t[n+1][target+1];
        
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
            for(int j=1;j<=target;++j){
                if(ans[i-1]<=j){
                    t[i][j] = t[i-1][j-ans[i-1]] + t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;++i)
            sum+=nums[i];
        if(sum & 1)
            return 0;
        return solve(nums,sum>>1);
    }
};
