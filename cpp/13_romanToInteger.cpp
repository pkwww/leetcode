class Solution {
public:
    int romanToInt(string s) {
        map<char, int> r2i = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = r2i[s[0]];
        for (int i = 1; i < s.size(); i++) {
            int currVal = r2i[s[i]];
            int prevVal = r2i[s[i-1]];
            result += currVal;
            if (currVal > prevVal) {
                result -= 2*prevVal;
            }
        }
        return result;
    }
};
