// loop {
//     提取子路径（/中的字符串）；
//     是 . 则不压栈，是 .. 则出栈，否则压栈。
// }
// 连接子路径
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
