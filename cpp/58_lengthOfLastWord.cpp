#include <string>
using std::string;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.size() - 1;
        for (; i >= 0; i--) {
            if (s[i] != ' ')
                break;
        }
        for (; i >= 0; i--) {
            if (s[i] == ' ')
                return count;
            count++;
        }
        return count;
    }
};
