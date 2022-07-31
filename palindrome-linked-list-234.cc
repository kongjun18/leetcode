// 经典的快慢指针，参考 LC19 remove-nth-node-from-end-of-list。
//
// LC19 删除链表的倒数第 N 个节点，fast 指针先走 N 步，然后 slow 和 fast 同步前
// 进，fast 为 nullptr 时，slow 指针刚好在倒数第 N 个节点。
//
// 使用和 LC19 相同的思路，利用快慢指针之间的距离一遍找到链表中点。快慢指针同时
// 触发，快指针一次走两步，慢指针一次走一步，快指针为 nullptr 时，刚好快慢指针
// 相差半个链表。
//
// 在慢指针前进的过程中，边走边反转链表，慢指针走到链表中点时，链表一分为二，分
// 别遍历两个链表查看节点值是否相等即可判断是否回文。
//
// 这里有个大坑，链表长度为奇数和偶数时，快指针无路可走时，指针的位置是不同的，
// 需要专门处理。当链表为奇数时，fast 走到 fast->next 为 nullptr；当链表为偶数时，
// fast 走到 fast 为 nullptr。链表长度为偶数时，slow 刚好指向第二个链表头；链表
// 长度为奇数时，slow 刚好指向链表正中间。
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next) {
      fast = fast->next ? fast->next->next : nullptr;
      ListNode *slow_next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = slow_next;
    }
    if (fast) { // odd
      slow = slow->next;
    }

    while (slow) {
      if (prev->val != slow->val) {
        return false;
      }
      slow = slow->next;
      prev = prev->next;
    }
    return true;
  }
};
