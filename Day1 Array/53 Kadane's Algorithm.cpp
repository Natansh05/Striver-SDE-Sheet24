// link - https://leetcode.com/problems/maximum-subarray/description/

// Optimal Code here
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int ans = INT_MIN;
        for(int i=0;i<n;++i){
            total+=nums[i];
            ans = max(total,ans);
            if(total<0)
                total = 0;
            
        }
        return ans;
    }
};
