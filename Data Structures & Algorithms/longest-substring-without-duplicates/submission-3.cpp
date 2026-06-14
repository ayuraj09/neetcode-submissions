class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int i=0;
        int ans = 0;
        for(int j=i;j<s.length();j++){
            mp[s[j]]++;
            while(i<=j && mp.size()!=(j-i+1)){
               auto it = mp.find(s[i]);
                it->second--;
                if (it->second == 0) {
                    mp.erase(it);
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
