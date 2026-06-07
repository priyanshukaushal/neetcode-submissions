class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i,j;
        i = j = 0;
        vector<int> freq(26,0);
        int ans = 0;
        while(j < n) {
            freq[s[j]-'A']++;
            int mostFreq = 0;
            int total = j-i+1;
            for(int f : freq) mostFreq = max(mostFreq, f);
            while(total-mostFreq > k) {
                freq[s[i]-'A']--;
                i++;
                total = j-i+1;
                for(int f : freq) mostFreq = max(mostFreq, f);
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
