#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = area;
        int w = 1;
        for (int i = 1; i <= sqrt(area); i++) {
            if (area % i == 0) {
                w = i;
                l = area / i;
            }
        }
        return {l, w};
    }
};
