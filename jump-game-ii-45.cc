// Greedy Algorithm. See it's twin jump-game-55.
//
// We should jump to a position such that we can jump as far as possible from
// that position.
//
// CORNER CASE: If we've already reached the end, we don't need to jump.
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int i = 0;
        while (i < nums.size()-1) {
            int steps = nums[i];
            int next_index = i+1;
            for (int j = i+1; j<= i+steps && j <nums.size(); j++) {
                // j == nums.size()-1 means that we've reached the end.
                if (next_index+nums[next_index] <= j+nums[j] || j == nums.size()-1) {
                    next_index = j;
                }
            }
            i = next_index;
            count++;
        }
        return count;
    }
};
