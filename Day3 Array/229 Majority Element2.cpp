// link - https://leetcode.com/problems/majority-element-ii/description/

// Brute force approach 
// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        int n = nums.size();
        int k = n/3;
        unordered_map<int,int> map;
        for(int i=0;i<n;++i){
            map[nums[i]]++;
        }
        vector<int> ans;
        for(auto i:map){
            if(i.second > k)
                ans.push_back(i.first);
        }
        return ans;
    }
};



// Optimal Approach
// Time Complexity - O(N)
// Space Complexity - O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0,cnt2 = 0;
        int el1 = INT_MIN,el2 = INT_MIN;

        int n = nums.size();
        for(int i=0;i<n;++i){
            if(cnt1==0 && el2!=nums[i]){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0 && el1!=nums[i]){
                el2 = nums[i];
                cnt2++;
            }
            else if(el1==nums[i])   cnt1++;
            else if(el2==nums[i])   cnt2++;

            else {
                cnt1--;
                cnt2--;
            }
        }

        // return {el1,el2};

        cnt1=0,cnt2=0;

        for(int i=0;i<n;++i){
            if(el2==nums[i])   cnt2++;
            else if(el1==nums[i])  cnt1++;
        }

        vector<int> ans;
        int mini = n/3;
        if(cnt1>mini)
            ans.push_back(el1);
        if(cnt2>mini)
            ans.push_back(el2);

        return ans;
    }
};
