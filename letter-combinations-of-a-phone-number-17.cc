class Solution {
public:
  vector<string> letterCombinations(string digits) {
    // 注意：digits 为空时，backtracking() 第一个 if 为真，压入空表到 result
    // 中。
    if (!digits.empty()) {
      backtracking(digits, 0);
    }
    return result;
  }

private:
  string letters;
  vector<string> result;
  unordered_map<char, string> num2chars{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };

  void backtracking(string digits, int start) {
    if (letters.size() == digits.size()) {
      result.push_back(letters);
      return;
    }
    for (char ch : num2chars[digits[start]]) {
      letters.push_back(ch);
      backtracking(digits, start + 1);
      letters.pop_back();
    }
  }
};
