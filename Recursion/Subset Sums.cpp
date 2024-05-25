// link - https://www.geeksforgeeks.org/problems/subset-sums2234/1
// Time Complexity - O(2^N)
// Space Complexity - O(2^N)

class Solution {
    private:
    void solve(vector<int> nums,int n,int i,int sum,vector<int> &ans){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        solve(nums,n,i+1,sum+nums[i],ans);
        solve(nums,n,i+1,sum,ans);
        return;
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        solve(arr,n,0,0,ans);
        return ans;
    }
};
