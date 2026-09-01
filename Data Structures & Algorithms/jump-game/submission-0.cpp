class Solution {
public:
    bool canJump(vector<int>& nums) {
    //  vector<int> arr(nums.size(),-1);
     int canReach = 0;
     for(int i=0;i<nums.size();i++){
        if(canReach>=i)
            canReach = max(nums[i]+i,canReach);
        cout<<canReach<<" ";
        }
    
    return canReach>=nums.size()-1;
    }
};


