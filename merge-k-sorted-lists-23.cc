// 对于 k 个有序链表，每次取 k 个有序链表的最小节点，添加到结果链表末尾。
//
// 关键在于降低“在 k 个有序链表中查找最小节点”的复杂度，这里使用堆维护最小节点。
//
// 另一个难点在于，每次从堆中取到最小节点后，如何将该节点的下一个节点加入堆中，
// 直接将链表节点指针加入即可，不要加入链表在数组中的下标。
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *dummy = new ListNode{};
    // 小于号是大顶堆，这里需要的是小顶堆
    auto cmp = [](ListNode *lhs, ListNode *rhs) { return lhs->val > rhs->val; };
    // 注意自定义比较器的优先级队列声明
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
    for (ListNode *list : lists) {
      if (list) {
        q.push(list);
      }
    }
    ListNode *prev = dummy;
    while (!q.empty()) {
      ListNode *temp = q.top();
      q.pop();
      prev->next = temp;
      prev = prev->next;
      if (temp->next) {
        q.push(temp->next);
      }
    }
    return dummy->next;
  }
};
