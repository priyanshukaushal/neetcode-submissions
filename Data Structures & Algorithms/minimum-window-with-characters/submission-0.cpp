class Solution {
public:
    bool doesContain(vector<int> &freqs, vector<int> &freqt) {
        for(int i = 0; i<58; i++) {
            if(freqs[i] < freqt[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> freqt(58,0);
        vector<int> freqs(58,0);
        for(char c : t) freqt[c-'A']++;
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int ansi = -1;

        while(j < n) {
            freqs[s[j]-'A']++;
            bool match = doesContain(freqs,freqt);
            while(match) {
                if(ans > j-i+1) {
                    ans = j-i+1;
                    ansi = i;
                }
                freqs[s[i]-'A']--;
                i++;
                match = doesContain(freqs,freqt);
            }
            j++;
        }
        if(ansi == -1) return "";
        return s.substr(ansi,ans);
    }
};
