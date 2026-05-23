class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &it : freq) {
            int frequency = it.second;
            int number = it.first;
            bucket[frequency].push_back(number);
        }
        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};