// link - https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1
// Time Complexity - O(NlogN)
// Space Complexity - O(K)

class Solution {
    typedef pair<int,int> p;
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        bool flag = 0;
        for(auto it : mp){
            pq.push({it.second,it.first});
            if(flag == 0 && pq.size()>k)
                flag = 1;
            if(flag){
                pq.pop();
            }
        }
        vector<int> ans(k,0);
        
        for(int i= k-1;i>=0;--i){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
