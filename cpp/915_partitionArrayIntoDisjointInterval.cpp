#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool check_valid_partition(const vector<int>& A, int left_len) {
        auto left_max = max_element(A.begin(), A.begin() + left_len);
        auto right_min = min_element(A.begin() + left_len, A.end());
        
        return *left_max <= *right_min;
    }
    int partitionDisjoint(vector<int>& A) {
        
        int left_max = A[0];
        int l = 0;
        for (int r = 1; r < A.size(); ++r) {
            while (l < r && left_max > A[r]) {
                ++l;
                left_max = max(left_max, A[l]);
            }
        }
        return l + 1;
    }
};
