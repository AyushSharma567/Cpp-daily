//question: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        vector<vector<vector<int>>> arr(
            m, vector<vector<int>>(n, vector<int>(4, 0)));
        for (int i = 0; i < walls.size(); i++)
            mat[walls[i][0]][walls[i][1]] = -1;
        for (int i = 0; i < guards.size(); i++)
            mat[guards[i][0]][guards[i][1]] = 2;
        int left = 0, right = 1, up = 2, down = 3;
        for (int i = 0; i < m; i++) {
            int gg = -1;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1)
                    gg = -1;
                else if (mat[i][j] == 2)
                    gg = j;
                else if (mat[i][j] == 0)
                    arr[i][j][left] = gg;
            }
        }
        for (int i = 0; i < m; i++) {
            int gg = -1;
            for (int j = n - 1; j > -1; j--) {
                if (mat[i][j] == -1)
                    gg = -1;
                else if (mat[i][j] == 2)
                    gg = j;
                else if (mat[i][j] == 0)
                    arr[i][j][right] = gg;
            }
        }
        for (int j = 0; j < n; j++) {
            int gg = -1;
            for (int i = 0; i < m; i++) {
                if (mat[i][j] == -1)
                    gg = -1;
                else if (mat[i][j] == 2)
                    gg = j;
                else if (mat[i][j] == 0)
                    arr[i][j][up] = gg;
            }
        }
        for (int j = 0; j < n; j++) {
            int gg = -1;
            for (int i = m - 1; i > -1; i--) {
                if (mat[i][j] == -1)
                    gg = -1;
                else if (mat[i][j] == 2)
                    gg = j;
                else if (mat[i][j] == 0)
                    arr[i][j][down] = gg;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (arr[i][j][left] == -1 and arr[i][j][right] == -1 and
                    arr[i][j][up] == -1 and arr[i][j][down] == -1)
                    ans++;
        }
        return ans;
    }
};