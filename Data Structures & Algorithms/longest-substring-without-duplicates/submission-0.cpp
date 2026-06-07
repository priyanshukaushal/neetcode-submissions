class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> freq;
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < n) {
            freq[s[j]]++;
            while(i < n && freq[s[j]] >= 2) {
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
