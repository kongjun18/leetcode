// 用堆实现表达式的匹配。注意，数字可能不止一位，而且可能以 - 开头。
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string token: tokens) {
            if (token == "+" || token =="-" || token =="*" || token == "/") {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                int result;
                switch (token[0]) {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                }

                s.push(result);
            } else {
                int num = stoi(token);
                s.push(num);
            }
        }
        return s.top();
    }
};
