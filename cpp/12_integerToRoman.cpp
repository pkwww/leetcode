class Solution {
public:
    string intToRoman(int num) {
        map<int, string> i2r = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        
        string result = "";
        int l[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for (int i: l) {
            if (num < i)
                continue;
            int q = num / i;
            num %= i;
            for (int j = 0; j < q; j++)
                result += i2r[i];
        }
        return result;
    }
};
