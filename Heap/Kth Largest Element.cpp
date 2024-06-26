// link - https://leetcode.com/problems/kth-largest-element-in-an-array/
// Time Complexity - O(nlogk)
// Space Complexity - O(K)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > pq;
        int n = nums.size();
        for(int i=0;i<n;++i){
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};
