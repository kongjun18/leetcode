// Monoatomic Stack
//
// How much rain it can trap from position left is determined by either the first
// height[right] that is higher than height[left], or the highest height after left
// if all height[right] are shorter.
//
// 1. First higher height: standard monoatomic stack
// 2. Highest right height: if the newly-inserted element touches the stack top,
//    this element MUST be the highest right height for the stack top at that time.
//
//    Proof:
//    Because the stack is monoatomic, each time an old element inside the stack touch
//    a newly-inserted element, the newly-inserted element MUST be greater than
//    all elements above the old element and has poped all these elements.
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> distance(height.size(), -1);
        stack<int> s;
        for (int i = 0; i < height.size(); i++) {
            // First higher height: Standard monoatomic stack
            while (!s.empty() && height[s.top()] <= height[i]) {
                int left = s.top();                 s.pop();
                distance[left] = i;
            }
            // Special case for this question: Highest right height
            if (!s.empty()) {
                distance[s.top()] = i;
            }
            s.push(i);
        }

        int ans = 0;
        for (int left = 0; left < height.size(); /* skip */ ) {
            if (distance[left] == -1) {
                left++;
                continue;
            }

            int right = distance[left];
            int min_height = min(height[left], height[right]);
            for (int j = left+1; j < right; j++) {
                ans += min_height - height[j];
            }
            left = right;
        }
        return ans;
    }
};
