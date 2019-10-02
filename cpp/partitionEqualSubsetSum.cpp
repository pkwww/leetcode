#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        
        int k = target + 1;
        
        vector<vector<bool>> arr;
        arr.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            arr[i].resize(k);
            for (int j = 0; j < k; j++) {
                arr[i][j] = false;
            }
        }
        
        arr[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j < k; j++) {
                int backtrack_num = j - nums[i];
                if (backtrack_num < 0) {
                    arr[i][j] = arr[i-1][j];
                } else {
                    arr[i][j] = arr[i-1][j] || arr[i-1][backtrack_num];
                }
            }
        }
        
        return arr[nums.size()-1][k-1];
    }
};
