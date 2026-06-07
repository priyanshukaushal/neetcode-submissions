class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i,j;
        i = j = 0;
        vector<int> freq(26,0);
        int ans = 0;
        int mostFreq = 0;
        while(j < n) {
            freq[s[j]-'A']++;
            mostFreq = max(mostFreq,freq[s[j]-'A']);
            while((j-i+1)-mostFreq > k) {
                freq[s[i]-'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
