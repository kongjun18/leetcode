// 暴力模拟
//
// 对于大小为 N 的数组，移动 k 位，移动后的下标为 j = (i+k)%N。
// 暴力遍历每一种可能即可。
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        // 移动 i 位
        for (int i = 0; i < s.size(); i++) {
            bool found = true;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != goal[(j+i)%s.size()]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
        return false;
    }
};
