// 备注：
//     阿里云一面问了这个题，只给出了暴力解法。
//
// ==暴力解法==
// 解题思路：
//     先“对齐”两链表，然后同步遍历，直到遇到相同节点。
// 技巧：
//     维持不变量，即 headA 不短于 headB，避免负责的条件判断。
//
// ==双指针==
// 解题思路：
//     假设 A、B 两链表相交，长度分别为 a、b，相交部分长度为 c，那么 A 表头到
//     相交节点 node，的节点数为 a-c，链表 B 为 b-c。
//
//     两指针 pa、pb 分别从 A、B 表头出发，每次向前一个节点。pa 指针走到 A 链表
//     尾后（nullptr）后，从 B 链表出发继续遍历。pb 指针走到 B 链表尾后（nullptr）
//     后，从 A 链表出发继续遍历。


// 暴力解法
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

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while (a != b) {
        a = a? a->next : headB;
        b = b? b->next : headA;
    }
    return a;
  }
};
