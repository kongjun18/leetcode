// 这题和 Leetcode 18 4sum 是姊妹题。
// 暴力解复杂度为 O(n^4)。最外围两层循环后，实际上要求的就是两数之和有多少组合。
// 一种思路是 3sum-15 排序加双指针，但是由于这里求下标，不可以进行排序。
//
// 直接遍历两个数组，求出两数之和的数量即可。
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
