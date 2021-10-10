#include <vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        
        vector<vector<int>> table{};
        table.reserve(m+1);
        for (int i = 0; i < m+1; ++i) {
            table.push_back(vector<int>(n+1, 0));
        }
        
        int max_len = 0;
        int max_pos = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i] == B[j]) {
                    table[i+1][j+1] = table[i][j] + 1;
                    if (table[i+1][j+1] > max_len) {
                        max_len = table[i+1][j+1];
                        max_pos = i;
                    }
                } else {
                    table[i+1][j+1] = 0;
                }
            }
        }
        return max_len;
    }
};
