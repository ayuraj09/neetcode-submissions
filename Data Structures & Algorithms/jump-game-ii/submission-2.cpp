class Solution {
public:
   int jump(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1)
            return 0;

        int maxReach = 0;    
        int currentEnd = 0; 
        int minSteps = 0;

        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);

            // Need to make a jump
            if (i == currentEnd) {
                minSteps++;
                currentEnd = maxReach;

                if (currentEnd >= n - 1)
                    return minSteps;
            }
        }

        return minSteps;
    }
};
















