// link - https://leetcode.com/problems/subsets/description/
// Time Complexity - O(2^N)
// Space Complexity - O(2^N)

class Solution {
    void solve(vector<int> &nums,vector<int> temp,int i,int n,vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        solve(nums,temp,i+1,n,ans);
        temp.push_back(nums[i]);
        solve(nums,temp,i+1,n,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(nums,temp,0,n,ans);
        return ans;
    }
};
