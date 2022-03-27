// 递归解法
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1) {
      return list2;
    }
    if (!list2) {
      return list1;
    }
    if (list1->val < list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
  }
};

// 迭代解法 1：如果任意一个链表不为空，将小的节点添加到新链表末尾。
//
// 这个实现太罗嗦了，下面的实现更加简洁。
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *prev = dummy;
    while (list1 || list2) {
      if (!list1) {
        prev->next = list2;
        list2 = nullptr;
        continue;
      }
      if (!list2) {
        prev->next = list1;
        list1 = nullptr;
        continue;
      }
      if (list1->val > list2->val) {
        prev->next = list2;
        list2 = list2->next;
      } else {
        prev->next = list1;
        list1 = list1->next;
      }
      prev = prev->next;
    }
    return dummy->next;
  }
};


// 先合并链表，直到有链表为空，将非空链表直接接到尾巴上。
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *prev = dummy;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }
      prev = prev->next;
    }
    prev->next = list1 ? list1 : list2;
    return dummy->next;
  }
};
