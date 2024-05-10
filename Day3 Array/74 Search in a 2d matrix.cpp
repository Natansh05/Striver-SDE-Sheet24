// link - https://leetcode.com/problems/search-a-2d-matrix/description/

// Time Complexity - O(log(mn))
// Space Complexity - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m = nums.size();

        int s=0,e=m-1;
        int mid = 0;
        int it = mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid][0]<=target){
                it = mid;
                cout<<it<<endl;
                s = mid+1;
            }
            else if(nums[mid][0]>target){
                e = mid-1;
            }
        }

        // cout<<it<<endl;

        int n = nums[0].size();
        s = 0,e = n-1;
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[it][mid] > target){
                e = mid-1;
            }
            else if(nums[it][mid] < target){
                s = mid+1;
            }
            else{
                cout<<mid<<endl;
                return true;
            }
        }
        cout<<mid<<endl;
        return false;
    }
};



// Better approach and easier code
// Time Complexity - O(log(mn))
// Space Complexity - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};
