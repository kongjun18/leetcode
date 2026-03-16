// 对于 k 个有序链表，每次取 k 个有序链表的最小节点，添加到结果链表末尾。
//
// 关键在于降低“在 k 个有序链表中查找最小节点”的复杂度，这里使用堆维护最小节点。
//
// 实现：
// 1. 第一种实现：聚焦于 Node，直接把 Node* 插入到堆中。
// 2. 第二种实现：聚焦于 N-way merge，把 N-way 链表的 ID 插入道堆中。

// 第一种实现：聚焦于 Node，直接把 Node* 插入到堆中。
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


// 第二种实现：聚焦于 N-way merge，把 N-way 链表的 ID 插入道堆中。
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [&](int lhs, int rhs) {
            return lists[lhs]->val > lists[rhs]->val;
        };
        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
        for (int i = 0; i < lists.size(); i++) {
            if (!lists[i]) {
                continue;
            }
            heap.push(i);
        }

        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (!heap.empty()) {
            int merge = heap.top();
            heap.pop();

            ListNode *node = lists[merge];
            ListNode *next = node->next;
            node->next = nullptr;
            lists[merge] = next;

            curr->next = node;
            curr = curr->next;

            if (lists[merge]) {
                heap.push(merge);
            }
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
