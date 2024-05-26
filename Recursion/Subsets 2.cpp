// link - https://leetcode.com/problems/subsets-ii/description/
// Time Complexity - O(2^N)
// Space Complexity - O(2^N)

class Solution {
    private:
    void solve(vector<int> &nums,vector<int> temp,int size,int i,int n,set<vector<int>> &st){
        if(i==n){
            st.insert(temp);
            return;
        }

        solve(nums,temp,size,i+1,n,st);
        
        temp.push_back(nums[i]);
        solve(nums,temp,size + 1,i+1,n,st);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> temp;
        int n = nums.size();
        solve(nums,temp,0,0,n,st);

        vector<vector<int>> ans;

        for(auto& v : st){
            ans.push_back(v);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};https://leetcode.com/problems/subsets-ii/description/
