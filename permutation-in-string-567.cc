// 滑动窗口
//
// 这道题有两种解法，一种是用固定长度的滑动窗口，一种是用变长的滑动窗口。
//
// ## 定长滑动窗口
// 字符串的排列是固定长度的，设置一个固定长度的滑动窗口向右滑动，每次滑动前判断
// 该窗口是否是目标字符串的排列（异位词）。
//
// 这道题和 number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold-1343
// 原理相同，但是无法直接将字符串的字符当作数字求和，原因是可能存在相同长度的不
// 同字符串的元素和相等，如"bbb"和"abc"。
//
// ## 变长滑动窗口
// 固定长度的滑动窗口的解法，需要每次遍历窗口判断窗口是否是异位词，判断的条件是
// 窗口和目标字符串长度相等，且字符出现次数相同。使用变长的滑动窗口，确保右边界
// 字符出现次数大于等于 0，且长度等于目标字符串（此时窗口字符出现次数必定等于目
// 标字符的次数）。
//
// 变长的滑动窗口解法避免了每次遍历窗口，性能更好。find-all-anagrams-in-a-string-438
// 解法相同，但测试用例字符串比较长，定长窗口会超时。
class Solution {
public:
    // 错误解法：通过求和字符串的值判断是否是异位词。
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

    // 变长窗口
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        for (const char c : s1) {
            m[c]++;
        }
        for (int start = 0, end=0; end < s2.size(); end++) {
            m[s2[end]]--;
            while(m[s2[end]] < 0) {
                m[s2[start]]++;
                start++;
            }
            if ((end-start+1) == s1.size()) {
                return true;
            }
        }
        return false;
    }

    // 定长窗口
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
