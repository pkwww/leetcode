#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        int max_sum = numeric_limits<int>::min();
        
        int n = A.size();
        for (int k = 0; k < n; k++) {
            int sum = 0;
            for (int i = 0; i < A.size(); i++) {
                int index = (n - k + i) % n;
                sum += A[index] * i;
            }
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
