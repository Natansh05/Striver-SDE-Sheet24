// link - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Time Complexity - O(N)
// Space Complexity - O(1)


class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    ios_base::sync_with_stdio(0);
    int ans = 0;
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s[r]];
      while (count[s[r]] > 1)
        --count[s[l++]];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
