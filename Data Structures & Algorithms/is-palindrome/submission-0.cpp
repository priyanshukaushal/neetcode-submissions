class Solution {
public:
    bool isAlphaNumeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        while(i < j) {
            while(i < j && !isAlphaNumeric(s[i])) i++;
            while(j > i && !isAlphaNumeric(s[j])) j--;
            if(i >= j) break;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
