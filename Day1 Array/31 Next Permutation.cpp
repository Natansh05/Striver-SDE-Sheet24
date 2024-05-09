// STL APPROACH 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
        return;
    }
};


// IMPLEMENTATION OF ABOVE STL APPROACH
// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        for(int i=n-2;i>=0;--i){
            if(nums[i+1]>nums[i]){
                ind = i;
                break;
            }
        }

        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=i;--i){
            if(nums[i]>nums[ind]){
                swap(nums[ind],nums[i]);
                break;
            }
        }

        reverse(nums.begin()+ind+1,nums.end());
        return;
    }
};
