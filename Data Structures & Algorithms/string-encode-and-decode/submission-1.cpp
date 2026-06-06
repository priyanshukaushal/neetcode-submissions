class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs) {
            ans.append(to_string(s.length()) + '@' + s);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.length();

        while(i<n) {
            int j = i;
            while(s[j] != '@') j++;
            int l = stoi(s.substr(i,j-i));
            i = j+1;
            ans.push_back(s.substr(i,l));
            i = i+l;
        }
        return ans;
    }
};
