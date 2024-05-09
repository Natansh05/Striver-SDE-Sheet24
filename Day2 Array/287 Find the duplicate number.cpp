// link - https://leetcode.com/problems/find-the-duplicate-number/description/
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]!=i+1){
                if(nums[i]==nums[nums[i]-1])
                    return nums[i];
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                ++i;
            }
        }

        for(int i=0;i<n;++i){
            if(nums[i]!=i+1)
                return nums[i];
        }
        return nums[n-1];
    }
};
