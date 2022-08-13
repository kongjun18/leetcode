// 没有难度，注意进位与两链表长度不一定相等即可。
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode{};
    ListNode *prev = head;
    bool carry = false;
    while (l1 || l2 || carry) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
      }
      if (l2) {
        sum += l2->val;
      }
      carry = ((sum % 10) != sum);
      sum %= 10;
      prev->next = new ListNode(sum);
      prev = prev->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return head->next;
  }
};
