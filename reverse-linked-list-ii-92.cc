// 使用 reverse-linked-list 中的两种迭代方法反转区间
//
// 将下一个节点放到最前面
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy_head = new ListNode(0, head);
    ListNode *prev = dummy_head;
    ListNode *curr = dummy_head->next;
    ListNode *next = nullptr;
    for (int i = 0; i < left - 1; ++i) {
      prev = curr;
      curr = curr->next;
    }
    for (int i = 0; i < right - left; ++i) {
      next = curr->next;
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
    }
    return dummy_head->next;
  }
};

// 当前节点指向上一个节点
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;
    int n = left;
    ListNode *left_node = dummy;
    for (int i = 1; i < left; ++i) {
      left_node = curr;
      curr = curr->next;
    }

    ListNode *new_tail = curr;
    for (int i = 0; i <= right - left; ++i) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    left_node->next = prev;
    new_tail->next = curr;
    return dummy->next;
  }
};
