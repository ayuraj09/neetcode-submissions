class Solution {
public:

    int getRow(int target, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[mid][0] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    }

    bool checkExist(int target, vector<vector<int>>& matrix, int row){
        int m = matrix[0].size();
        int l = 0;
        int r = m-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[row][mid]==target){
                return 1;
            }else if(matrix[row][mid]>target){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return 0;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = getRow(target, matrix);
        cout<<row;
        if(row == -1) return 0;
        return checkExist(target, matrix, row);
    }
};