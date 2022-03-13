// 解题思路：
//     先“对齐”两链表，然后同步遍历，直到遇到相同节点。
// 技巧：
//     维持不变量，即 headA 不短于 headB，避免负责的条件判断。
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto a_size = listSize(headA);
    auto b_size = listSize(headB);
    if (a_size < b_size) {
      swap(headA, headB);
      swap(a_size, b_size);
    }
    for (auto i = b_size; i < a_size; ++i) {
      headA = headA->next;
    }
    while (headA && headB) {
      if (headA == headB) {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return nullptr;
  }

private:
  int listSize(const ListNode *head) const noexcept {
    int size = 0;
    while (head) {
      ++size;
      head = head->next;
    }
    return size;
  }
};
