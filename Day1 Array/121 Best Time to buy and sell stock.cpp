// link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// OPTIMAL APPROACH BY ME 
// Time complexity - O(N)
// Space complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e6,maxi = -1,profit = 0;

        for(int i=0;i<n;++i){
            if(nums[i]<mini){
                mini = nums[i];
                maxi = nums[i];
            }
            else if(nums[i]>maxi){
                maxi = nums[i];
                profit = max(maxi-mini,profit);
            }

        }
        return profit;
    }
};


// OPTIMISED CODE FOT THE SAME 
// Time complexity - O(N)
// Space complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        ios_base::sync_with_stdio(false);
        
        int mini = 1e9,profit = 0;
    
        for(int i=0;i<prices.size();i++){
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i] - mini);
        }
        return profit;
    }
};
