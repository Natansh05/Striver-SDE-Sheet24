// Optimal Code added
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0,mid = 0,high = n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                ++low;
                ++mid;
            }
            else if(nums[mid]==1){
                ++mid;
            }
            else{
                swap(nums[mid],nums[high]);
                --high;
            }
        }
        return;
    }
};