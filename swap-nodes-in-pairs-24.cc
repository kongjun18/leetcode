//
// 注意：
//     - 访问指针前必须判断是否为空。
//     - head 指向节点，当节点位置变化后，head 不指向起始节点（head 指向
//     的节点不再是起始节点）。
//
// 迭代解法：无哨兵节点
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *curr = head;
    ListNode *next = curr ? curr->next : nullptr;
    ListNode *prev = nullptr;
    head = next ? next : curr;
    while (curr && next) {
      curr->next = next->next;
      next->next = curr;
      if (prev) {
        prev->next = next;
      }
      prev = curr;
      curr = curr->next;
      if (curr) {
        next = curr->next;
      }
    }
    return head;
  }
};

// 迭代解法：哨兵节点
// 哨兵节点避免了前面非哨兵迭代解法中的判断。
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummyHead = new ListNode(0, head);
    while (temp->next != nullptr && temp->next->next != nullptr) {
      ListNode *node1 = temp->next;
      ListNode *node2 = temp->next->next;
      temp->next = node2;
      node1->next = node2->next;
      node2->next = node1;
      temp = node1;
    }
    return dummyHead->next;
  }
};

// 递归解法
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
  }
};

