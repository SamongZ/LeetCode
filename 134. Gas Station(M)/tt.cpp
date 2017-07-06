/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).

You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0) return -1;
        int size = max(gas.size(), cost.size());
        int index;
        int total = 0;
        int minSum = INT_MAX;
        for (int i = 0; i < size; ++i) {
            total += (i >= gas.size() ? 0 : gas[i]) - (i > cost.size() ? 0 : cost[i]);
            if (total < minSum) {
                minSum = total;
                index = i + 1;
            }
        }
        return (total < 0) ? -1 : (index % size);
    }
};
