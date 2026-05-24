class Solution {
public:

    bool isAlphaNum(char ch){
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

    char toLowerCase(char ch){
        if(ch >= 'A' && ch <= 'Z'){
            return ch - 'A' + 'a';
        }
        return ch;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while(i <= j){
            while(i < j && !isAlphaNum(s[i])) i++;
            while(i < j && !isAlphaNum(s[j])) j--;
            if(toLowerCase(s[i]) != toLowerCase(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};