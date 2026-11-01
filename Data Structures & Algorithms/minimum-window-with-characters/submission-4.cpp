class Solution {
public:

    int getIndex(char c) {
        if(c >= 'a' && c <= 'z')
            return c - 'a';

        return c - 'A' + 26;
    }

    bool isExist(vector<int> &fs, vector<int> &ft) {
        for(int i = 0; i < 52; i++) {
            if(fs[i] < ft[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        if(s.length() < t.length()) return "";

        vector<int> ft(52, 0);
        vector<int> fs(52, 0);

        for(int i = 0; i < t.length(); i++) {
            ft[getIndex(t[i])]++;
        }

        int l = 0, minl = INT_MAX;
        pair<int,int> ans = {-1, -1};

        for(int r = 0; r < s.length(); r++) {

            fs[getIndex(s[r])]++;

            while(isExist(fs, ft)) {

                if(minl > r - l + 1) {
                    ans = {l, r};
                    minl = r - l + 1;
                }

                fs[getIndex(s[l])]--;
                l++;
            }
        }

        if(minl == INT_MAX) return "";

        return s.substr(ans.first, minl);
    }
};