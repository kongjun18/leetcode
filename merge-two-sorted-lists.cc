/*
 * https://leetcode.com/problems/merge-two-sorted-lists/submissions/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    ListNode* res = nullptr;
    ListNode* prev = nullptr;
    while (list1 && list2) {
      if (list2 && list2->val < list1->val) {
        auto temp = list2->next;
        list2->next = list1;
        if (prev) {
          prev->next = list2;
        }
        prev = list2;
        list2 = temp;
      } else {
        prev = list1;
        list1 = list1->next;
      }
      if (!res)
        res = prev;
    }

    if (!res)
      res = list1 ? list1 : list2;
    else if (list2)
      prev->next = list2;
    return res;
  }
};

/*
 * list1 为空：
 *   - 表 1 为空
 *   - 表 1 比表 2 先遍历完
 *
 * list2 为空：
 *   - 表 1 为空
 *   - 表 1 比表 2 先遍历完
 *
 * 特殊情况：
 *   - 表 2 第一个节点插入到表 1 第一个节点之前
 *   - 两个表均为空
 *
 * 解决方案：
 *   - 如果进入 while 循环，res 总是指向正确的起始节点。
 *   - prev 总是指向最后一个遍历节点之前（可能为 nullptr）。
 * 使用这两个维护这两个契约，如果 res 为 nullptr，说明最少一个表空。
 * 如果 res 不是 nullptr，只需要考虑将表 2 插入到表 1 后面。
 *
 * 复杂的原因在于有太多 edge case，直接排除这些 edge case 简化编程：
 *   - 开头判断输入是否为空
 *   - 总是将第一个元素大的表归并到第一个元素小的表中，避免起始节点的判断。
 */
class Solution {
  public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    if (!list1)
      return list2;
    if (!list2)
      return list1;

    if (list1->val > list2->val)
      swap(list1, list2);
    ListNode* res = list1;
    ListNode* prev = nullptr;
    while (list1 && list2) {
      if (list2 && list2->val < list1->val) {
        auto temp = list2->next;
        list2->next = list1;
        prev->next = list2;
        prev = list2;
        list2 = temp;
      } else {
        prev = list1;
        list1 = list1->next;
      }
    }

    if (list2)
      prev->next = list2;
    return res;
  }
};
