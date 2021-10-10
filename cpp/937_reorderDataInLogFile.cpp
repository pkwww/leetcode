#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto iter = std::stable_partition(logs.begin(), logs.end(), [](const string& s) {
            return isalpha(s[s.find(" ")+1]);
        });
        
        std::sort(logs.begin(), iter, [](const string& s1, const string& s2) {
            int first_space1 = s1.find(" ");
            int first_space2 = s2.find(" ");
            int sub_cmp = s1.substr(first_space1 + 1).compare(s2.substr(first_space2 + 1));
            if (sub_cmp < 0) {
                return true;
            } else if (sub_cmp > 0) {
                return false;
            } else {
                return (s1.substr(0, first_space1) <= s2.substr(0, first_space2));
            }
        });
        return logs;
    }
};
