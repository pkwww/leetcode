#include <string>
using namespace std;
class Solution {
public:
    int ctoi(char c) {
        return c - '0';
    }
    
    void toNine(int first, string& s) {
        for (int i = first; i < s.size(); i++) {
            s[i] = '9';
        }
    }
    
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        for (int i = s.size() - 2; i >= 0; i--) {
            char lsd = s[i + 1];
            char& msd = s[i];
            if (msd > lsd) {
                toNine(i + 1, s);
                msd -= 1;
            }
        }
        return stoi(s);
    }
};
