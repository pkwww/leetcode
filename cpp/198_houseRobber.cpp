// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed, the only constraint stopping you
// from robbing each of them is that adjacent houses have security system
// connected and it will automatically contact the police if two adjacent houses
// were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of
// each house, determine the maximum amount of money you can rob tonight without
// alerting the police.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> money;
        money.reserve(nums.size());
        money[0] = nums[0];
        money[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int rob_i = *max_element(money.begin(), money.begin()+(i-2)+1) + nums[i];
            cout << i << ": " << rob_i << endl;
            int not_rob_i = money[i-1];
            money[i] = max(rob_i, not_rob_i);
        }
        return money[nums.size()-1];
    }
};
