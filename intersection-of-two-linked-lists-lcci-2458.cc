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
//     两链表相交时，分别从两链表头部同步向后走，两个指针不能相交的原因在于，
//     两个指针走过的路程不相等。
//
//     何时两个指针能同步走过相同的距离？将两链表的一个分叉摘下来放到另一个分叉上，
//     这个新链表的长度就是两指针能同步走过的距离。
//
//     链表 A、B 分叉部分长度分别为 La 和 Lb，相交部分长度为 Li。两指针 pa、pb
//     分别从 A、B 同步向后走，指针走到尽头后从另一个链表头部开始走。最终两指针
//     走过距离为 La+Lb+Li 时由于走过的路程相同，最终必定相遇。如果两链表不相交，
//     Li 为 0，结论相同，但在 null 相遇。
//
//    *
//     *
//      *---------
//     *
//    *
//       |
//       V
//    ****-------


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
