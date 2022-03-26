class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

// 递归1:
// reverseListImpl(head) 翻转链表从 head 开始的部分，返回翻转后链表的尾指针。
// 记录下翻转后的头指针 new_head。
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    reverseListImpl(head);
    return new_head;
  }

private:
  ListNode *new_head = nullptr;
  ListNode *reverseListImpl(ListNode *head) {
    if (!head || !head->next) {
      new_head = head;
      return head;
    }
    ListNode *curr = reverseListImpl(head->next);
    curr->next = head;
    head->next = nullptr;
    return head;
  }
};

// 递归2：
//
// 假设链表如下：
// N1 → ... → Nk−1 → Nk → Nk+1 → ... → Nm → ∅
// 
// 若从节点 Nk+1 到 Nm 已经被反转，而我们正处于 Nk。
// N1 → ... → Nk−1 → Nk → Nk+1 ← ... ←Nm
// 
// 让 Nk.next.next = Nk，Nk.next = NULL
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};
