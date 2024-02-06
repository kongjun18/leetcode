// 一道很基本的哈希表
//
// 注意：
// - 两个数相同
// - 避免重复遍历
func maxOperations(nums []int, k int) int {
    res := 0
    min := func(a, b int) int {
        if (a < b) {
            return a;
        }
        return b;
    }
    m :=  make(map[int]int)
    for _, val := range nums {
        m[val]++
    }
    for num, _ := range m {
        if _, ok := m[k-num]; ok {
            cnt := 0
            if num == (k-num) {
                cnt = int(m[num] / 2)
            } else {
                cnt = min(m[num], m[k-num])
            }
            m[num] = 0
            m[k-num] = 0
            res += cnt
		}
    }
    return res;
}

