// 这题和 Leetcode 18 4sum 是姊妹题。
// - Leetcode 18 如果用哈希会非常复杂，解决之道是”暴力解法思路，双指针优化”。
// - 这道题暴力解法非常简单，难在能否想到用哈希表计数。
//
// 思路：
// a+b+c+d=0 --> a+b=-(c+d)，那么先计算出所有 a+b 之和的个数 N，
// 找到和为 -(a+b) 的 (c,d)，得到 N 组(a,b,c,d)。迭代 (c,d) 即可得到所有四元组。
func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	counter := make(map[int]int)
	for _, a := range nums1 {
		for _, b := range nums2 {
			counter[a+b]++
		}
	}

	cnt := 0
	for _, a := range nums3 {
		for _, b := range nums4 {
			cnt += counter[-(a + b)]
		}
	}
	return cnt
}
