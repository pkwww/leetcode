#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string join(vector<string>& vs, const string& delim) {
        string ret = "";
        for (int i = 0; i < vs.size(); i++) {
            ret += vs[i] + delim;
        }
        return ret;
    }
    
    vector<string> removeComments(vector<string>& source) {
        string joined_source = join(source, "\n");
        string target = "";
        for (int i = 0; i < joined_source.size(); i++) {
            if (joined_source[i] == '/' && joined_source[i+1] == '*') {
                for (i = i + 3; !(joined_source[i-1] == '*' && joined_source[i] == '/'); i++){}
                continue;
            }
            if (joined_source[i] == '/' && joined_source[i+1] == '/') {
                // line comment
                for (i = i + 2; !(joined_source[i] == '\n'); i++) {}
            }
            target += joined_source[i];
        }
        
        vector<string> ret{};
        string line = "";
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == '\n' && line == "") {
                continue;
            } else if (target[i] == '\n' && line != "") {
                ret.push_back(line);
                line = "";
                continue;
            } else {
                line += target[i];
            }
        }
        
        return ret;
    }
};
