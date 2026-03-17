// Greedy Algorithm
//
// Sort intervals such that overleaping is determined by the right boundry.
// Iterate through intervals, if a overleaped interval pair is found, remove
// the interval whose right boundry is longer to make the right boundry away
// from the left boundry of the next interval.
class Solution {
private:
    bool overlap(const vector<int> &a, const vector<int> &b) {
        return !(a[1] <= b[0] || b[1] <= a[0]);
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[0] < rhs[0];
        });
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (overlap(intervals[i-1], intervals[i])) {
                if (intervals[i-1][1] < intervals[i][1]) {
                    vector<int> temp(intervals[i]);
                    intervals[i] = intervals[i-1];
                    intervals[i-1] = temp;
                }
                ans++;
            }
        }
        return ans;
    }
};
