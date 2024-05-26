// link - https://leetcode.com/problems/combination-sum/
// Time Complexity - O(N*2^N*K)
// Space Complexity - O(2^N)

class Solution {
    private:
    void solve(vector<int> nums,vector<int> temp,int i,int n,int sum,int target,vector<vector<int>> &ans){
        
        if(target == sum){
            ans.push_back(temp);
            return;
        }
        if(i==n || sum > target)
            return;

        solve(nums,temp,i+1,n,sum,target,ans);
        temp.push_back(nums[i]);
        solve(nums,temp,i,n,sum+=nums[i],target,ans);
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>> ans;
        // sort(nums.begin(),nums.end());
        vector<int> temp;
        int n = nums.size();
        solve(nums,temp,0,n,0,target,ans);
        return ans;
    }
};
