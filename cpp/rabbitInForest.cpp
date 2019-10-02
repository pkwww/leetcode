/*
In a forest, each rabbit has some color. Some subset of rabbits (possibly all of
them) tell you how many other rabbits have the same color as them. Those answers
are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into
the array. The smallest possible number of rabbits in the forest is therefore 5:
3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0

Note:

    answers will have length at most 1000.
    Each answers[i] will be an integer in the range [0, 999].
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.empty()) {
            return 0;
        }
        
        int res = 0;
        unordered_map<int, int> ans_count_map{};
        for (int ans: answers) {
            auto find = ans_count_map.find(ans);
            if (find == ans_count_map.end()) {
                // cannot find
                res += ans + 1;
                if (ans != 0) {
                    ans_count_map[ans] = ans;
                }
            } else {
                find->second--;
                if (find->second == 0) {
                    ans_count_map.erase(find);
                }
            }
        }
        return res;
    }
};
