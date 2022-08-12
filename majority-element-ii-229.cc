// 摩尔投票法
// 1. 选票：按照以下步骤遍历选票
//     1. 确定候选人：如果候选人选票为 0，则将当前票选的人设置为候选人。这在还没有
//        投过票前尤为重要，票只能投给一个人，所以不会和粗线两个候选人是同一个人的情况。
//     2. 增加选票：当前票选的人是候选人，则增加该候选人的票数。
//     3. 对抗：当前票选的人不是候选人，则减少票数。这一步相当于两方厮杀，同归于尽。
//
// 2. 计数：可能没有候选人胜出（比如 10 个人选举 2 人，并且每人都要获得超过 1/3 的票数。
//          因此必须遍历选票判断候选人是否胜出。
//
// 姊妹题 majority-element-169，求数组中出现次数超过 n/2 的元素。
// majority-element-169 相当于投票选举出一个人，这里相当于投票选举出两个人。
//
// 有两种情况：
// - 投票给两个候选人中的任意一个，不需要对抗，按照选举一个人的情况递增票数。
// - 投票给两个候选人之外的人，需要对抗，两个候选人的票数都要减一。
//

// 错误示范
//
// 没有理清摩尔投票的流程，导致出现两个候选人是同一个人的错误情况。
//
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         // 1. num == canda == candb
//         // 2. num == candb || num == candb
//         // 3. num != canda && num != canda
//         int cand1 = nums[0];
//         int cand2 = nums[0];
//         int cnt1 = 0;
//         int cnt2 = 0;
//         for (const auto num : nums) {
//             if (cnt1 > 0 && cnt2 > 0 && cand1 == cand2 && cand1 == num) {
//                 cnt1++;
//                 cnt2++;
//             } else if (cnt1 > 0 && cand1 == num) {
//                 cnt1++;
//             } else if (cnt2 > 0 && cand2 == num) {
//                 ++cnt2;
//             } else if (cnt1 > 0 && cand1  != num) {
//                 --cnt1;
//             } else if (cnt2 > 0 && cand2 != num) {
//                 --cnt2;
//             } else {
//                 if (cnt1 == 0 ) {
//                     ++cnt1;
//                     cand1 = num;
//                 }
//                 if (cnt2 == 0) {
//                     ++cnt2;
//                     cand2 = num;
//                 }
//             }
//         }
//         cnt1 = 0;
//         cnt2 = 0;
//         vector<int> ans;
//         for (const auto num : nums) {
//             if (cand1 == num) {
//                 ++cnt1;
//                 if (cnt1 > nums.size()/3) {
//                     ans.push_back(cand1);
//                     break;
//                 }
//             }
//             if (cand1 != cand2 && cand2 == num) {
//                 ++cnt2;
//                 if (cnt2 > nums.size()/3) {
//                     ans.push_back(cand2);
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for (auto & num : nums) {
            if (vote1 > 0 && num == element1) { //如果该元素为第一个元素，则计数加1
                vote1++;
            } else if (vote2 > 0 && num == element2) { //如果该元素为第二个元素，则计数加1
                vote2++;
            } else if (vote1 == 0) { // 选择第一个元素
                element1 = num;
                vote1++;
            } else if (vote2 == 0) { // 选择第二个元素
                element2 = num;
                vote2++;
            } else { //如果三个元素均不相同，则相互抵消1次
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto & num : nums) {
            if (vote1 > 0 && num == element1) {
                cnt1++;
            }
            if (vote2 > 0 && num == element2) {
                cnt2++;
            }
        }
        // 检测元素出现的次数是否满足要求
        if (vote1 > 0 && cnt1 > nums.size() / 3) {
            ans.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3) {
            ans.push_back(element2);
        }

        return ans;
    }
};
