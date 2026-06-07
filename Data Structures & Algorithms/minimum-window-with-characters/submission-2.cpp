class Solution {
public:

    string minWindow(string s, string t) {
        unordered_map<char,int> freqt, freqs;
        for(char c : t) freqt[c]++;
        int need = freqt.size();
        int have = 0;
        int ansSize = INT_MAX;
        int ansStart = -1;
        int n = s.length();
        int i,j;
        i = j = 0;
        while(j < n) {
            freqs[s[j]]++;
            if(freqt.find(s[j]) != freqt.end() && freqt[s[j]] == freqs[s[j]]) {
                have++;
            }
            while(need == have) {
                if(j-i+1 < ansSize) {
                    ansSize = j-i+1;
                    ansStart = i;
                }
                freqs[s[i]]--;
                if(freqt.find(s[i]) != freqt.end() && freqt[s[i]] > freqs[s[i]]) {
                    have--;
                }
                i++;
            }
            j++;
        }
        if(ansStart == -1) return "";
        return s.substr(ansStart,ansSize);
    }
};
