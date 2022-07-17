// 算法：
//
// loop {
//     提取子路径（/中的字符串）；
//     是 . 则不压栈，是 .. 则出栈，否则压栈。
// }
// 连接子路径

// 难点：
// - 提取子串时如何能够正确处理连续的 / ？？？
//
//   先思考不能存在连续 / 的情况。扫描字符串，非 / 的字符 append 到字符串 curr 中，
//   遇到 / 时，将保存的字符串压入到字符串数组中，并将字符串 curr 置空。
//
//   再拓展到存在连续 / 的情况。每次遇到 / 压入 curr 字符串后，都会将 curr 置空，
//   所以不存在连续 / 的情况下的算法已经能够在存在连续 / 的情况下工作。
//
//   每次遇到 / 都会压入字符串，可能出现压入空字符串的情况，比如遇到 "///"，可以
//   只压入非空子串。
//
// - 如何处理最后的 / 后的字符？
//   最后返回时判断 curr 是否为空，非空则压入即可。
//
// - 如何将拼接所有子串为合法路径？
//   合法路径由多个 /xxx 组成，在循环中拼接即可。


///////////////////////////////////////////////////////////////////
//                      第一次自己的实现
///////////////////////////////////////////////////////////////////

// 使用状态机的思路，遇到 xx 则如何如何。这个实现没有编写“提取子串”的函数，导致
// 逻辑不清晰。
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        int start = 0;
        int end = 0;
        for ( ; start != std::string::npos; start = end) {
            start = path.find_first_not_of("/", start);
            if (start == std::string::npos) {
                break;
            }
            end = path.find_first_of("/", start);
            if (end == std::string::npos) {
                end = path.size();
            }
            const auto subpath = path.substr(start, end - start);
            if (subpath == "."s) {
                continue;
            }
            else if (subpath == ".."s) {
                if (!q.empty()) {
                    q.pop_back();
                }
            } else {
                q.push_back(subpath);
            }
        }
        string ss = "/";
        while (!q.empty()) {
            ss.append(q.front());
            q.pop_front();
            ss.append("/");
        }
        if (ss.size() != 1 ) {
            ss.erase(ss.size() - 1, 1);
        }
        return ss;
    }
};


///////////////////////////////////////////////////////////////////
//                      参考 Leetcode 题解                       //
///////////////////////////////////////////////////////////////////
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names = split(path, '/');
        vector<string> st;
        string ans;
        for (auto name : names) {
            if (name == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else if (name != ".") {
                st.push_back(name);
            }
        }
        if (st.empty()) {
            ans = "/";
        } else {
            for (int i = 0; i < st.size(); ++i) {
                ans += "/" + st[i];
            }
        }
        return ans;
    }
    vector<string> split(string str, char delem) const {
        vector<string> res;
        string ans;
        for (auto ch : str) {
            if (ch == delem) {
                if (!ans.empty()) {
                    res.push_back(ans);
                }
                ans.clear();
            } else {
                ans += ch;
            }
        }
        if (!ans.empty()) {
            res.push_back(ans);
        }
        return res;
    }
};


