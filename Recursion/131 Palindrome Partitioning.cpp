// link - https://leetcode.com/problems/palindrome-partitioning/description/
// Time complexity: O(2^n.n)
// Space complexity: O(2^n.n)


class Solution {
    bool isPalindrome(string s,int left,int right){
        while(left<=right){if(s[left++]!=s[right--]){return false;}}
        return true;
    }

    vector<vector<string>> ans;
    void solve(int ind,string s,vector<string> &temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i< s.size();++i){
            if(isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,temp);
                temp.pop_back();
            }
            else{
                continue;
            }

        }

    }
public:
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(0);
        vector<string> temp;
        // cout<<isPalindrome("");
        solve(0,s,temp);
        return ans;
    }
};
