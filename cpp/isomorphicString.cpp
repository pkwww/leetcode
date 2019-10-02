#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mst;
        map<char, char> mts;
        for (int i = 0; i < s.size(); i++) {
            char s_c = s[i];
            char t_c = t[i];
            auto search_st = mst.find(s_c);
            auto search_ts = mts.find(t_c);
            if (search_st == mst.end() && search_ts == mts.end()) {
                // not find
                mst.insert({s_c, t_c});
                mts.insert({t_c, s_c});
            } else {
                if (search_st->second != t_c) {
                    return false;
                }
                if (search_ts->second != s_c) {
                    return false;
                }
            }
        }
        return true;
    }
};
