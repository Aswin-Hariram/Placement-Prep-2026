class Solution {
public:
    void solve(int row, int col, vector<vector<int>>& image, int color,
               int orginalColor) {

        int n = image.size();
        int m = image[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m ||
            image[row][col] != orginalColor) {
            return;
        }
        image[row][col] = color;

        solve(row + 1, col, image, color, orginalColor);
        solve(row - 1, col, image, color, orginalColor);
        solve(row, col + 1, image, color, orginalColor);
        solve(row, col - 1, image, color, orginalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if (image[sr][sc] == color) {
            return image;
        }
        solve(sr, sc, image, color, image[sr][sc]);

        return image;
    }
};
