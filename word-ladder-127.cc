// Shortest Path
//
// If word A and word B only differs by 1 single letter, let word A point to word B.
// By doing so, we can construct a graph, and calculate the shortest path from
// the begin word to end word.
class Solution {
private:
    bool adjcent(const string &a, const string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            diff += (a[i] != b[i]);
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<vector<int>> graph(wordList.size());
        int end = find(wordList.cbegin(), wordList.cend(), endWord) - wordList.cbegin();
        if (end >= wordList.size()) {
            return 0;
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < wordList.size(); j++) {
                if (adjcent(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            cout << i << ": ";
            for (const auto n : graph[i]) {
                cout << n << " ";
            }
            cout << endl;
        }
        vector<int> dist(wordList.size(), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist.back() = 1;
        pq.push({1, dist.size()-1});

        while (!pq.empty()) {
            const auto [d, n] = pq.top(); pq.pop();

            if (d > dist[n]) {
                continue;
            }

            for (const int neighbor : graph[n]) {
                if (dist[neighbor] > (d+1)) {
                    dist[neighbor] = d+1;
                    pq.push({d+1, neighbor});
                }
            }
        }
       return dist[end] == INT_MAX ? 0 : dist[end];
    }
};
