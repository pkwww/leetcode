// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long first = 1;
        long last = (long)n + 1l;
        while (first < last) {
            long mid = first + (last - first) / 2;
            if (!isBadVersion((int)mid))
                first = mid + 1;
            else
                last = mid;
        }
        return first;
    }
};
