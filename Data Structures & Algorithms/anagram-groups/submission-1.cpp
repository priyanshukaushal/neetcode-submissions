class Solution {
public:
    string hash(vector<int> &freq) {
        string ans = "";
        for(int i = 0; i<26; i++) {
            ans.push_back(char(freq[i]));
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;

        for(string s : strs) {
            int n = s.length();
            vector<int> freq(26,0);
            for(int i = 0; i<n; i++) {
                freq[s[i]-'a']++;
            }

            map[hash(freq)].push_back(s);
        }
        for(pair<string,vector<string>> p : map) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
