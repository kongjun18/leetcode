// 字节跳动（西瓜视频后端）一面题目
// 
// 反转当前 k 个节点，然后将后面已反转的链表接到尾巴上。
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head) {
      return head;
    }
    ListNode *curr = head;
    ListNode *prev = nullptr;
    for (int i = 1; i < k; ++i) {
      if (!curr->next) {
        return head;
      }
      curr = curr->next;
    }

    curr = head;
    ListNode *new_tail = curr;
    for (int i = 0; i < k; ++i) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    new_tail->next = reverseKGroup(curr, k);
    return prev;
  }
};
