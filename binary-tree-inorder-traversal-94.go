/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	var res []int
	var stack []*TreeNode
	curr := root
	for len(stack) > 0 || curr != nil {
		if curr != nil {
			stack = append(stack, curr)
			curr = curr.Left
		} else {
			node := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			res = append(res, node.Val)
			if node.Right != nil {
				curr = node.Right
			}
		}
	}
	return res
}
