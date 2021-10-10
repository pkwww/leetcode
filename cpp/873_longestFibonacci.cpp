#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> set{A.begin(), A.end()};
        
        int max_len = 2;
        for (int i = 0; i < A.size() - 2; i++) {
            for (int j = i + 1; j < A.size() - 1; j++) {
                int len = 2;
                int x = A[j];
                int y = A[i] + A[j];
                while (set.find(y) != set.end()) {
                    //found
                    int z = x + y;
                    x = y;
                    y = z;
                    len++;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len == 2 ? 0 : max_len;
    }
};
