// 滑动窗口
//
// 字符串的排列是固定长度的，设置一个固定长度的滑动窗口向右滑动，每次滑动前判断
// 该窗口是否是目标字符串的排列。
//
// 这道题和 number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold-1343
// 原理相同，但是无法直接将字符串的字符当作数字求和，原因是可能存在相同长度的不
// 同字符串的元素和相等，如"bbb"和"abc"。
class Solution {
public:
    // bool checkInclusion(string s1, string s2) {
    //     int target = 0;
    //     for (const int ch : s1) {
    //         target += ch;
    //     }
    //     int sum = 0;
    //     for (int start = 0, end =0; end < s2.size();++end) {
    //         sum += int(s2[end]);
    //         if ((end-start + 1) == s1.size()) {
    //             if (sum == target) {
    //                 return true;
    //             }
    //             sum -= s2[start];
    //             start++;
    //         }
    //     }
    //     return false;
    // }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        for (const char c : s1) {
            m[c]++;
        }
        unordered_map<char, int> c;
        for (int start = 0, end=0; end < s2.size(); end++) {
            c[s2[end]]++;
            if ((end-start+1) == s1.size()) {
                bool found = true;
                for (const auto [ch, times] : m) {
                    if (times != c[ch]) {
                        found = false;
                    }
                }
                if (found) {
                    return true;
                }
                c[s2[start]]--;
                start++;
            }
        }
        return false;
    }
};
