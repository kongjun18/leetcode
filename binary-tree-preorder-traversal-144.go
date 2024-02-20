/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
	var res []int
	var heap []*TreeNode
	curr := root
	for {
		if curr == nil {
			if len(heap) == 0 {
				break
			}
			curr = heap[len(heap)-1]
			heap = heap[:len(heap)-1]
		}
		res = append(res, curr.Val)
		if curr.Right != nil {
			heap = append(heap, curr.Right)
		}
		curr = curr.Left
	}
	return res
}
