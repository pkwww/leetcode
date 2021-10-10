#include <vector>
using namespace std;

class Solution {
public:
    int binary_search(vector<int>& numbers, int start, int end, int target) {
        while (start < end) {
            int middle_index = (end - start) / 2 + start;
            int middle_element = numbers[middle_index];
            if (target < middle_element) {
                end = middle_index;
            } else if (target == middle_element) {
                return middle_index;
            } else {
                start = middle_index;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1; 
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (target < sum) {
                j--;
            } else if (target == sum) {
                return {i + 1, j + 1};
            } else {
                i++;
            }
        }
    }
};
