// link - https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
    private:

    vector<int> nsl(vector<int> nums,int n){
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;++i){
            while(1){
                if(st.empty()){
                    ans[i]= -1;
                    st.push({nums[i],i});
                    break;
                }
                else if(st.top().first<nums[i]){
                    ans[i] = st.top().second;
                    st.push({nums[i],i});
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        return ans;
    }

    vector<int> nsr(vector<int> nums,int n){
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i = n-1;i>=0;--i){
            while(1){
                if(st.empty()){
                    ans[i] = n;
                    st.push({nums[i],i});
                    break;
                }
                else if(st.top().first<nums[i]){
                    ans[i] = st.top().second;
                    st.push({nums[i],i});
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        return ans;
    }

    int MAH(vector<int> &heights){
        int n = heights.size();
        vector<int> right = nsr(heights,n);
        vector<int> left = nsl(heights,n);

        int ans = 0;
        int cal = 0;
        for(int i=0;i<n;++i){
            cal = heights[i] * (right[i]-left[i]-1);
            ans = max(cal,ans);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(0);
        return MAH(heights);
    }
};
