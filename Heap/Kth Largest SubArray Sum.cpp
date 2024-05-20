// link - geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
// Time Complexity - O(N^2logK)
// Space Complexity - O(K)


class Solution{
public:
    int kthLargest(vector<int> &nums,int n,int k){
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum = 0;
        bool flag  = 0;
        for(int i=0;i<n;++i){
            sum = 0;
            for(int j=i;j<n;++j){
                sum+=nums[j];
                pq.push(sum);
                if(flag==0 && pq.size()>k)
                    flag = 1;
                if(flag)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
