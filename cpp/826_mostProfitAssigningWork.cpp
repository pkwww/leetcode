#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> zip(const vector<int>& v1, const vector<int>& v2) {
        vector<pair<int, int>> res;
        res.reserve(v1.size());
        for (int i = 0; i < v1.size(); i++) {
            res.push_back(make_pair(v1[i], v2[i]));
        }
        return res;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::sort(worker.begin(), worker.end());
        vector<pair<int, int>> zipped = zip(difficulty, profit);
        std::sort(zipped.begin(), zipped.end(), [](auto p1, auto p2) {
            if (p1.first < p2.first) {
                return true;
            } else if (p1.first > p2.first) {
                return false;
            } else {
                return p1.second <= p2.second;
            }
        });
        
        int res = 0;
        int prev_j = 0;
        int max = 0;
        for (int ablity: worker) {
            for (int j = prev_j; j < zipped.size(); j++) {
                if (zipped[j].first > ablity) {
                    break;
                } else {
                    max = std::max(max, zipped[j].second);
                    prev_j = j;
                }
            }
            res += max;
        }
        
        return res;
    }
};
