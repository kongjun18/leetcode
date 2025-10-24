// the brutal-force solution is to iterate through all positions. There is no
// algorithm can reduce the complexity by a magnitude.
//
// Solution 1 (clearer)
// Due to the direction is fixed, so we can calculate the gas level change at
// each position. We can propose a gready algorithm: select the position with
// maximun gas level as the starting position. Although the gready result is not
// global best result, as it's possible to get more gas at the next station of
// a position with minimum gas, this gready strategy can skip some unnecessary
// searches.
//
//
// Solution 2 (better complexity)
// We can search from position 0, if the gas ran out, we select this position as
// new position, and restart search from this position until the result is found.
//
// Onece we encounter a position where gas ran out, this is the next possible
// start position.
//
// Consider positions in the range [start_pos, ran_out_pos], we
// can not exceed the ran_out_pos from each position in the range: the start_pos
// adds gas, so we have less gas from other positions and thus ran_out_pos is the
// longest position we can reach. The next possible start position must be the ran_out_pos.

// Solution1 - My solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> gas_changes(gas.size());
        vector<pair<int, int>> start_points;
        for (int i = 0; i < gas.size(); i++) {
            gas_changes[i] = gas[i]-cost[i];
            if (gas_changes[i] > 0) {
                start_points.emplace_back(gas_changes[i], i);
            }
        }
        // Corner Case
        if (gas_changes.size() == 1 && gas_changes[0] >= 0) {
            return 0;
        }
        sort(start_points.begin(), start_points.end());

        for (int j = start_points.size()-1; j >= 0; j--) {
            int start = start_points[j].second;
            int capacity = 0;
            int curr = start;
            for (int i = 0; i < gas.size(); i++) {
               capacity += gas_changes[curr];
               int next = (curr+1) % gas.size();
               // Corner case: next == start - gas ran out but the travel is finshied.
               if (capacity < 0 || (capacity == 0 && next != start)) {
                   break;
               }
               curr = next;
            }
            if (curr == start) {
                return start;
            }
        }
        return -1;
    }
};

// Solution2 - Leetcode official solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};
