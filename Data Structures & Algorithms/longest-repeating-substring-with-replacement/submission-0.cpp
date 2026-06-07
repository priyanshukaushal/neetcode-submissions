class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int maxFreq = 0;
            vector<int> freq(26,0);
            for(int j = i; j<n; j++) {
                freq[s[j]-'A']++;
                maxFreq = max(freq[s[j]-'A'], maxFreq);
                int total = j-i+1;
                int rem = total-maxFreq;
                if(rem <= k) ans = max(ans, total);
            }
        }
        return ans;
    }
};
