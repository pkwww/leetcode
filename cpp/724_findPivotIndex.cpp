#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }
        int left_sum = 0;
        int right_sum = accumulate(nums.begin()+1, nums.end(), 0);
        if (left_sum == right_sum) {
            return 0;
        }
        for (int i = 1; i < nums.size(); i++) {
            left_sum += nums[i-1];
            right_sum -= nums[i];
            if (left_sum == right_sum) {
                return i;
            }
        }
        return -1;
    }
};
