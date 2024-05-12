// link - https://leetcode.com/problems/longest-consecutive-sequence/description/

// ---------------------------BETTER APPROACH----------------------
// Time Complexity - O(nlogn)
// Space Complexity - O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // better approach than brute force 
        //  sorting
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0 || n==1)
            return n;

        int last = INT_MIN;
        int cnt = 1;
        int ans = 1;

        for(int i=0;i<n;++i){
            if(nums[i]==last)
                continue;
            
            if(last==nums[i]-1){
                cnt++;
                last = nums[i];
                ans = max(cnt,ans);
            }
            else{
                last = nums[i];
                cnt = 1;
            }
            
        }
        return ans;
    }
};






// ---------------------------OPTIMAL APPROACH----------------------
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        int n = nums.size();
        int start = -1;
        int cnt = 1,ans = 1;

        unordered_set<int> st;

        for(int i=0;i<n;++i)
            st.insert(nums[i]);

        for(int i=0;i<n;++i){
            if(st.find(nums[i]-1)!=st.end())
                continue;
            else{
                start = nums[i];
                while(st.find(start+1)!=st.end()){
                    cnt++;
                    start++;
                }

                ans = max(ans,cnt);
                cnt=1;
            }
        }
        return ans;
    }
};
