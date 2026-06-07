class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> last;
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < n) {
            if(last.find(s[j]) != last.end() && last[s[j]] >= i) {
                i = last[s[j]]+1;
            }
            last[s[j]] = j;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
