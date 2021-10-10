class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int res = a + b;
        for (int i = 1; i < n; i++) {
            a = b;
            b = res;
            res = a + b;
        }
        return res;
    }
};
