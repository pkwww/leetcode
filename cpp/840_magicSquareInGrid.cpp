#include <vector>
using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        
        int count = 0;
        int col_size = grid[0].size();
        int row_size = grid.size();
        for (int i = 0; i < row_size - 2; i++) {
            for (int j = 0; j < col_size - 2; j++) {
                bool skip = false;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (grid[i+k][j+l] > 9 || grid[i+k][j+l] < 1) {
                            skip = true;
                        }
                    }
                }
                if (skip) {
                    continue;
                }
                int row0 = grid[0+i][0+j] + grid[0+i][1+j] + grid[0+i][2+j];
                int row1 = grid[1+i][0+j] + grid[1+i][1+j] + grid[1+i][2+j];
                int row2 = grid[2+i][0+j] + grid[2+i][1+j] + grid[2+i][2+j];
                int col0 = grid[0+i][0+j] + grid[1+i][0+j] + grid[2+i][0+j];
                int col1 = grid[0+i][1+j] + grid[1+i][1+j] + grid[2+i][1+j];
                int col2 = grid[0+i][2+j] + grid[1+i][2+j] + grid[2+i][2+j];
                int dia1 = grid[0+i][0+j] + grid[1+i][1+j] + grid[2+i][2+j];
                int dia2 = grid[0+i][2+j] + grid[1+i][1+j] + grid[2+i][0+j];
                if (row0 == row1 && row1 == row2 && row2 == col0 && col0 == col1 && col1 == col2
                   && col2 == dia1 && dia1 == dia2) {
                    count++;
                }
            }
        }
        return count;
    }
};
