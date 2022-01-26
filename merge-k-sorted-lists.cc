
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

// 陷阱：
//     陷入到指针中无法自拔，甚至弄出双重指针。
// 改进：
//     和向量上的归并排序类比，向量上的归并排序中，将归并两个有续向量，这里归并两个有序列表。
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        auto greater = [](ListNode* lhs, ListNode* rhs) {
            return lhs->val > rhs->val;
        };
        // 注意：
        //     - 构造函数参数是比较器。
        //     - 小于号默认是大顶堆。
        priority_queue<ListNode*, vector<ListNode*>, decltype(greater)> firsts(greater);
        for (const auto list : lists) {
            if (list) {
                firsts.push(list);
            }
        }
        if (firsts.empty()) {
            return nullptr;
        }
        // 技巧：
        //     先单独做一次操作，记录下第一个节点位置。之后的操作再用循环。
        // 类似方案还有：循环中相邻元素比较，一种方法如下：
        // int i = 0;
        // for ( ; i < containner.size() - 1; ++i ) {
        //   compare containner[i] and containner[i + 1];
        // }
        // 缺点在于 containner.size() 可能小于等于 0，溢出。
        // 第一个元素单独抽出来：
        // int i =0, j = 1;
        // for ( ; j < containner.size(); ++j ) {
        //   compare containner[j] and containner[j];
        //   ++i;
        // }
        // 避免了特殊条件降低心智负担，并且这种写法很容易变成快慢指针。
        ListNode* res = firsts.top();
        firsts.pop();
        ListNode* current = res;
        if (current->next) {
            firsts.push(current->next);
        }
        while (!firsts.empty()) {
            current->next = firsts.top();
            current = current->next;
            firsts.pop();
            if (current->next) {
                firsts.push(current->next);
            }
        }
        return res;
    }
};

////////////////////////////////////////////////////
//                   参考                         //
////////////////////////////////////////////////////
// 参考：https://leetcode.com/problems/merge-k-sorted-lists/discuss/1626710/C%2B%2B-oror-Brute-Force-To-Most-Optimal-oror-Explained
//
// [Brute_force] Merge first with second, then ans of that with third, then answer of that with fouth, and so on....................[If each list has n size and we have k lists, Then Complexity will be] O(n*k ^ 2)

class Solution { // This is Most Basic Approach
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* head = NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        ListNode* curr = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
            return NULL;
        ListNode* ans = lists[0];
        for (int i = 1; i < lists.size(); i++)
            ans = mergeTwoLists(ans, lists[i]);

        return ans;
    }
};

// Approach 2--> We can use map to store frequency of each ele -- O(nklog(nk)) Time and O(nk) space for map//
// Changing data of Linkedlist is not recommended[Explaind here in solution bcz we shold know where it fails], Highly avoidable bcz our Solution will not work when we have data as
// --User defined data not int or char//

class Solution {
public:
    map<int, int> mp;
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        for (int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            ListNode* nxt;
            while (curr) {
                ListNode* temp = curr;
                mp[curr->val]++;
                curr = curr->next;
                delete temp;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        for (auto X : mp) {
            for (int i = 1; i <= X.second; i++) {
                ListNode* temp = new ListNode(X.first);
                prev->next = temp;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};

// Approach 3-Using Divide and Conquer This approach doesn’t require extra space for heap except recursive call stack size(which is log(k))and works in O(nk Log k)
//
//     The idea is to pair up K lists and merge each pair in linear time
//     After the first cycle, K/2 lists are left each of size 2N. After the second cycle, K/4 lists are left each of size 4N and so on.
//     Repeat the procedure until we have only one list left.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* head = NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        ListNode* curr = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;

        return head;
    }

    ListNode* merge_k_helper(vector<ListNode*>& lists, int start, int end)
    {
        if (start > end)
            return NULL;

        if (start == end)
            return lists[start];
        ListNode* newhead;
        int mid = start + (end - start) / 2;
        ListNode* a = merge_k_helper(lists, start, mid);
        ListNode* b = merge_k_helper(lists, mid + 1, end);
        newhead = mergeTwoLists(a, b);
        return newhead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
            return NULL;
        int start = 0, end = lists.size() - 1;
        return merge_k_helper(lists, start, end);
    }
};
