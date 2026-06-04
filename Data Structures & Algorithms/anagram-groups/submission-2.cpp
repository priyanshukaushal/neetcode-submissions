class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        for(auto str : strs) {
            int n = str.length();
            vector<int> freq(26,0);
            for(int i = 0; i<n; i++) {
                freq[str[i]-'a']++;
            }
            string temp = "";
            for(int i = 0; i<26; i++) {
                int k = freq[i];
                char c = 'a'+i;
                while(k>0) {
                    temp.push_back(c);
                    k--;
                }
            }
            map[temp].push_back(str);
        }
        for(auto p : map) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
