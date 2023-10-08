// 滑动窗口
//
// 窗口是含有最多 2 种水果的连续子数组
//
// 向右拓展窗口，种类超过两种时缩小左边界，直到重新满足水果种类不超过 2 中。
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;
        int end = 0;
        int maxCount = 0;
        map<int, int> m;
        while (end < fruits.size()) {
            m[fruits[end]]++;
            while (m.size() > 2) {
                m[fruits[start]]--;
                if (m[fruits[start]] == 0) {
                    m.erase(fruits[start]);
                }
                start++;
            }
            maxCount = max(maxCount, end-start+1);
            end++;
        }
        return maxCount;
    }
};
