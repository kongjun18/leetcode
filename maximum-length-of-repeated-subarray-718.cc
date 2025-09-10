// 1. 哈希表找到 subarray 起始位置，然后开始搜索。
// 2. 动态规划。dp[i][j] 代表 A[i:] 和 A[j:] 的最大字串长度。
//    if A[i] ==  B[j]; dp[i][j] = dp[i+1][j+1] + 1
//    if A[i] != B[j]; dp[i][j] = 0
//    目标的最大字串长度就是 dp 数组的最大值
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> m;
        int len = 0;
        for (int i = 0; i < nums2.size(); i++) {
           m[nums2[i]].push_back(i);
        }
        for (int i =0; i < nums1.size(); i++) {
            for (const int j : m[nums1[i]]) {
                if (nums2.size() - j <= len) {
                    break;
                }
                int k = 0;
                while((i+k < nums1.size()) && (j+k < nums2.size())) {
                    if (nums1[i+k] == nums2[j+k]) {
                        len = max(len, k+1);
                        k++;
                    } else {
                        break;
                    }
                }
            }
        }
        return len;
    }
};
