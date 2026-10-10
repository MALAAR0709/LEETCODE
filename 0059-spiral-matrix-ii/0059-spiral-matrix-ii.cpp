class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // Left to right
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;

            // Top to bottom
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;

            // Right to left
            for (int i = right; i >= left && top <= bottom; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;

            // Bottom to top
            for (int i = bottom; i >= top && left <= right; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }

        return matrix;
    }
};