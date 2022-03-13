// 单调栈
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    st.push(0);
    vector<int> result(temperatures.size());
    for (int i = 1; i < temperatures.size(); ++i) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        result[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return result;
  }
};
