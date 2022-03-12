// 典型的快慢指针。类比跑步比赛，一开始跑得快的运动员在前面，只要时间足够长，跑的
// 快的肯定会超过跑得慢的至少一圈，并且中间运动员肯定会相遇。
//
// 跑步比赛起始时刻，运动员起点相同，模拟跑步比赛的快慢指针起始也相同。
// 起点不相同也正确，但无法维持“fast 指针走过的节点数恰好是 slow 指针的 2 倍”这
// 一不变量，并且需要额外判断(初始化)。
// class Solution {
// public:
//   bool hasCycle(ListNode *head) {
//     ListNode *slow = head;
//     ListNode *fast = slow ? slow->next : nullptr;
//     while (fast) {
//       if (slow == fast) {
//         return true;
//       }
//       slow = slow->next;
//       fast = fast->next;
//       if (fast) {
//         fast = fast->next;
//       }
//     }
//     return false;
//   }
// };

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next;) {
      if (slow == fast) {
        return true;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
};
