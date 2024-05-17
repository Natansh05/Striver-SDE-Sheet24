// link - https://leetcode.com/problems/trapping-rain-water/description/
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(0);
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int num = 0;

        for(int i=0;i<n;++i){
            num = max(num,height[i]);
            left[i]= num;
        }
        num = -1;
        for(int i=n-1;i>=0;--i){
            num = max(num,height[i]);
            right[i] = num;
        }

        int cnt = 0;
        for(int i=0;i<n;++i){
            cnt += min(left[i],right[i])-height[i];
        }

        return cnt;
    }
};


// same thing can be done by using next greater element approach ,usme we will use another N ki space and then directly jump to given index and add move ahead.......
