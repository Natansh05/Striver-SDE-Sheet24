// link - https://leetcode.com/problems/combination-sum-ii/description/
// Time Complexity - O(2^N * K)
// Space Complexity - O(2^N)

class Solution {
    void solve(vector<int> nums,vector<int> temp,int ind,int n,int target,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i = ind;i<n;++i){
            if(i > ind && nums[i]==nums[i-1])
                continue;
            if(nums[i]>target)
                return;
            temp.push_back(nums[i]);
            solve(nums,temp,i+1,n,target-nums[i],ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        ios_base::sync_with_stdio(0);
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums,temp,0,n,target,ans);
        return ans;
    }
};
