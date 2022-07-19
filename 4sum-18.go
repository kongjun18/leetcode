func fourSum(nums []int, target int) (ans [][]int) {
	sort.Slice(nums, func(i, j int) bool { return nums[i] < nums[j] })
	for i, _ := range nums {
		// 去重
		if i > 0 && nums[i-1] == nums[i] {
			continue
		}
		target -= nums[i]
		for j := i + 1; j < len(nums); j++ {
			// 去重
			if j > i+1 && nums[j-1] == nums[j] {
				continue
			}
			// 4 个数要在不同的位置，因此 l 不能等于 r
			for l, r := j+1, len(nums)-1; l < r; {
				sum := nums[j] + nums[l] + nums[r]
				if sum == target {
					ans = append(ans, []int{nums[i], nums[j], nums[l], nums[r]})
					// 1. 找到下一个不同的元素，可能出现符合条件的一对数。
					// 2. 如果找不到那么会出现 l >= r，退出 for 循环。
					// 3. 注意这里的实现技巧：先往前走一步再和后面的比较
					for l++; l < r && nums[l] == nums[l-1]; l++ {
					}
					for r--; l < r && nums[r] == nums[r+1]; r-- {
					}
					// 如果相邻元素相同，这两个分支已经实现了跳过重复元素。
				} else if sum < target {
					l++
				} else {
					r--
				}

			}
		}
		target += nums[i]
	}
	return
}
