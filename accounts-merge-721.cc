// Each node represents an email and the graph is a map
// which automatically merges accounts by the key (email).
class Solution {
private:
    vector<string> bfs(unordered_map<string, vector<string>> &graph, unordered_map<string, string> &nameByEmail, unordered_map<string, int> &visited, const string &start) {
        vector<string> out;
        const string name = nameByEmail[start];
        out.push_back(name);

        queue<string> q;
        q.push(start);
        visited[start] = 1;
        out.push_back(start);
        while (!q.empty()) {
            const auto email = q.front(); q.pop();
            const auto &otherEmails = graph[email];
            for (const auto &otherEmail : otherEmails) {
                if (visited[otherEmail]) {continue;}
                out.push_back(otherEmail);
                q.push(otherEmail);
                visited[otherEmail] = 1;
            }
        }
        sort(out.begin()+1, out.end());
        return out;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> nameByEmail;
        for (int i = 0; i < accounts.size(); i++) {
            const auto &account = accounts[i];
            const string name = account[0];
            for (int j = 1; j < account.size(); j++) {
                nameByEmail[account[j]] = name;
                for (int k = j; k < account.size(); k++) {
                    graph[account[j]].push_back(account[k]);
                    if (k != j) {
                        graph[account[k]].push_back(account[j]);
                    }
                }
            }
        }

        unordered_map<string, int> visited;
        vector<vector<string>> ans;
        for (auto it = graph.begin(); it != graph.end(); it++) {
            const auto &email = it->first;
            if (visited[email]) {continue;}
            ans.push_back(bfs(graph, nameByEmail, visited, email));
        }
        return ans;
    }
};
