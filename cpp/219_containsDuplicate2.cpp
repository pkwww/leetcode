#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> v_i;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto search = v_i.find(num);
            if (search == v_i.end()) {
                // not exist yet
                v_i.insert({num, i});
            } else {
                int diff = abs(i - search->second);
                if (diff <= k) {
                    return true;
                } else {
                    search->second = i;
                }
            }
        }
        return false;
    }
};
