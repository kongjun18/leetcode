// 暴力解法：
//     两遍扫描，第一次获得链表长度，第二次删除倒数第 n 个节点。

// 双指针（快慢指针）：
//     链表长度为 N，fast 指针走 n 步，再走 N - n 步到达尾后（nullptr）。
//
//     fast 和 slow 从 head 出发，fast 先走 n 步，然后 slow 和 fast 同步
//     前进，直到 fast 为 nullptr。fast 为 nullptr 时，slow 走了 N - n，
//     步，到达的节点就是倒数第 n 个节点。
//
//     删除链表需要获取当前节点的上一个节点，让 fast 多走一步（再走 N -
//     n - 1 步到达 nullptr），那么 slow 就可以少走一步，停留在倒数第 n
//     个节点的前继节点。
//
//     实现时注意 while (n-- >= 0) 循环 n + 1 次，因为每次判断都减一，
//     判断失败后 n 的值是 -1。


// 暴力解法实现
//
// class Solution {
// public:
//   ListNode *removeNthFromEnd(ListNode *head, int n) {
//     int size = listSize(head);
//     ListNode *pre = nullptr;
//     ListNode *curr = head;
//     for (int i = 0; i < size - n; ++i) {
//       pre = curr;
//       curr = curr->next;
//     }
//     if (pre) {
//       pre->next = curr->next;
//     } else {
//       head = curr->next;
//     }
//     return head;
//   }
//
// private:
//   int listSize(ListNode *head) {
//     int size = 0;
//     while (head) {
//       ++size;
//       head = head->next;
//     }
//     return size;
//   }
// };

// 快慢指针实现
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (n-- >= 0 && fast) { // n-- >= 0 循环 n + 1 次
      fast = fast->next;
    }
    if (n >= -1) { // 最后一次 n-- == 0，判断失败后 n 的值为 -1。
      return slow->next;
    }
    while (fast) {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = slow->next ? slow->next->next : nullptr;
    return head;
  }
};
