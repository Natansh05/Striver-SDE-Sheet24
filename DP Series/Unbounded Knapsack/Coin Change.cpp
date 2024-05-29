// link - https://leetcode.com/problems/coin-change/description/
// Time Complexity - O(N*Amount)
// Space Complexity - o(N*Amount)

class Solution {
    int solve(vector<int> nums,int sum){
        int n = nums.size();
        int t[n+1][sum+1];

        for(int i=0;i<=n;++i){
            for(int j=0;j<=sum;++j){
                if(i==0)
                    t[i][j] = INT_MAX - 1;
                if(j==0)
                    t[i][j] = 0;

                // corrwct insitialisation as jaha pe coin ki value 2 ho aur target = 1 ho
                // waha pe ye normal initialisation will take 1 coin of 2 , and sum = 2 > target , which 
                // may not be the correct ans , as humko chaiye 1 aur milega 2
                // it will not cause any error in outut , but still for consistency , this initialisation should
                // be used
                // if(i==1 && j!=0){
                //     if(j%nums[0] == 0 )
                //         t[i][j] = j/nums[0];
                //     else
                //         t[i][j] = INT_MAX-1;    
                // }
            }
        }

        for(int i=2;i<=n;++i){
            for(int j=1;j<=sum;++j){
                if( nums[i-1] <= j){
                    t[i][j] = min(1 + t[i][j-nums[i-1]] , t[i-1][j]);
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }

        if(t[n][sum] == INT_MAX - 1)
            return -1;
        return t[n][sum];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(0);
        return solve(coins,amount);
    }
};
