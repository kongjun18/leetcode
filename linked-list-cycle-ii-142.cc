// 不变量：fast 指针走过的节点数恰好是 slow 指针的 2 倍。
// fast 指针必在 slow 指针跑完一圈前超 slow 一圈并且一定相遇。
// 证明：
// 1. fast 超 slow 一圈
//     如果 slow 跑了一圈，那么 fast 肯定跑了两圈，所以一定超 slow 一圈。
// 2. fast 和 slow 一定相遇
//     slow 和 fast 起点相同，都是匀速前进，并且路线相同，考虑环形跑道，fast 第
//     一次遇到 slow 肯定是 slow 跑完一圈回到起点的时候。其他形状的链表同理。
//
// 设起点到环形入口点节点数 x，slow 指针在环中前进距离为 y，环(前进方向)剩余距离为 z。
// 则相遇时 fast 走过的节点数为 x + y + n(y + z)，slow 为 x + y + z。
// 消去 (x + y)，得到 x + y = n(y + z)。
// 移项得到：x = n(y + z) - y = (n - 1) + z。n 肯定大于等于 1（在这里等于 1）。
// 这个等式的意思是：从起点和环中快慢指针相遇的位置开始，两个指针每次走一个节点，
// 环中走 n - 1 圈，两指针一定能在入口相遇。
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
