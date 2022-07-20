/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 用栈控制节点的处理，后续遍历也可以使用类似的计数处理节点。
func preorderTraversal(root *TreeNode) []int {
	ans := []int{}
	var st []*TreeNode
	if root != nil {
		st = append(st, root)
	}
	for len(st) != 0 {
		curr := st[len(st)-1]
		st = st[:len(st)-1]
		ans = append(ans, curr.Val)

		if curr.Right != nil {
			st = append(st, curr.Right)
		}
		if curr.Left != nil {
			st = append(st, curr.Left)
		}
	}
	return ans
}
