class Solution {
public:

    int solve(int row, int col,vector<vector<int>>& triangle,int size,
        vector<vector<int>>& dp) {

        // Base case
        if(row == size - 1) {
            return triangle[row][col];
        }

        // Memoization
        if(dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        int down = solve(row + 1, col,triangle, size, dp);

        int diag = solve(row + 1, col + 1,triangle, size, dp);

        return dp[row][col] = triangle[row][col] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int size = triangle.size();

        vector<vector<int>> dp(size,vector<int>(size, INT_MAX));

        return solve(0, 0, triangle, size, dp);
    }
};
