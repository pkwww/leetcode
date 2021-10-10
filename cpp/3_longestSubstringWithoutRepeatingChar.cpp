#include <unordered_map>
using namespace std;

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        unordered_map<char, int> char_index_map = {};
        for (int i = 0, j = 0; j < s.size(); j++) {
            char curr = s[j];
            auto search = char_index_map.find(curr);
            if (search != char_index_map.end() && search->second >= i && search->second <= j) {
                // dup
                i = max(i, search->second + 1);
            } else {
                // not duplicate
                max_len = max(max_len, j - i + 1);
            }
            char_index_map[curr] = j;
        }
        return max_len;
    }
};
