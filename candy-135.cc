// Very similar to ./wiggle-subsequence-376.cc.
//
// SOLUTION: gready algorithm
//
// The rating value only affects it's neighbor, so it is a local variable. We
// can view the rating array as peaks and valleys. Valleys should get just 1
// candy such that other childs receives candies as less as possible. For a
// particular peak, it's candies depend on both neighbor, as the peak should have
// more candies than it's neighbor.
//
// We can find all valleys, and update the candy counts of children on both sides
// until a peak is reached.
//
// Notes
// - If two childs have the same ratting value, there is no candy count
//   requirement, so we should give them candies as less as possible.
// - Candy counts of a peak are determined by the maximum neighbor, so we should
//   use `std::max()`.
class Solution {
public:
    int candy(vector<int>& ratings) {
        bool downward = true;
        vector<int> valleys;
        vector<int> candies(ratings.size(), 0);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                if (downward) {
                    downward = false;
                    valleys.push_back(i-1);
                }
            } else {
                downward = true;
                if (i == ratings.size()-1) {
                    valleys.push_back(i);
                }
            }
        }
        if (valleys.empty()) {
            return 1;
        }
        for (int i = 0; i < valleys.size(); i++) {
            int valley = valleys[i];
            candies[valley] = 1;
            // left peak
            for (int j = valley; j-1 >= 0; j--) {
               if (ratings[j-1] > ratings[j]) {
                candies[j-1] = max(candies[j-1], candies[j]+1);
               } else if (ratings[j-1] == ratings[j]) {
                candies[j-1] = max(candies[j-1], 1);
               } else {
                    break;
               }
            }
            // right peek
            for (int j = valley; j+1 < ratings.size(); j++) {
                if (ratings[j+1] > ratings[j]) {
                    candies[j+1] = max(candies[j+1], candies[j]+1);
                } else if (ratings[j+1] == ratings[j]) {
                    candies[j+1] = max(candies[j+1],1);
                } else {
                    break;
                }
            }
        }
        return accumulate(candies.cbegin(), candies.cend(), 0);
    }
};
