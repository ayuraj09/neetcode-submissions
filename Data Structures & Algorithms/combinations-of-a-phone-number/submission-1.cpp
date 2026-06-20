class Solution {
public:
    vector<string> solve(string &digits,
                         unordered_map<char,string> &mp,
                         int idx) {

        if(idx == digits.size()) {
            return {""};
        }

        vector<string> res;
        vector<string> suffixes = solve(digits, mp, idx + 1);

        for(char ch : mp[digits[idx]]) {
            for(string &s : suffixes) {
                res.push_back(ch + s);
            }
        }

        return res;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char,string> mp = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
            {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}
        };

        return solve(digits, mp, 0);
    }
};