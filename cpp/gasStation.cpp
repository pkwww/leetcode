/*
 * There are N gas stations along a circular route, where the amount of gas at
station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
from station i to its next station (i+1). You begin the journey with an empty
tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit
once in the clockwise direction, otherwise return -1.
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        vector<int> net;
        net.resize(N);
        transform(gas.begin(), gas.end(), cost.begin(), net.begin(),
                  [](int a, int b) { return a - b; });
        int start = 0;
        int end = start;
        int acc = net[end];
        int step = end - start;
        while (start < N) {
            while (acc >= 0 && step < N) {
                end = (end + 1) % N;
                step++;
                acc += net[end];
            }
            if (step == N) {
                return start;
            }
            if (acc < 0) {
                acc -= net[start];
                start = start + 1;
                step--;
            }
        }
        if (step == N) {
            return start;
        }
        return -1;
    }
};
