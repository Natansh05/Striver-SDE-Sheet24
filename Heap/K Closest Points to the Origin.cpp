// link - 
// Time Complexity - O(NlogN)
// Space Complexity - O(K)

class Solution {
    typedef pair<float,int> pi;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& nums, int k) {
        ios_base::sync_with_stdio(0);
        int n = nums.size();
        priority_queue<pi> pq;
        int x,y;
        float sum;
        for(int i=0;i<n;++i){
            x = nums[i][0];
            y = nums[i][1];
            sum = sqrt(x*x + y*y);
            pq.push({sum,i});
            bool flag = 0;
            if(flag == 0 && pq.size()>k)
                flag = 1;
            if(flag)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            pi top = pq.top();
            pq.pop();
            ans.push_back({nums[top.second][0],nums[top.second][1]});
        }
        return ans;
    }
};
