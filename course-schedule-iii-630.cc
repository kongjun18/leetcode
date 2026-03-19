// Graph is not feasible since there is no clear prerequisite requirement for a course,
// it is impossible to construct a graph and thus transform the problem to a
// shortest path problem.
//
// The solution is gready algorithm. Sort courses in order of the last day, and then
// this problem is very similar to non-overlapping-intervals-435. We iterate
// through the courses, for each one, we try to add the course, if it violates
// the last day constraint, we pop the worst course that has longest duration.
//
//
// Proof of the correctness of gready algorithm by exchange argument:
// Suppose the sub-structure is not optimal once we remove the worst course that
// has the longest duration, there MUST be a course has longer duration, which
// contradicts with the fact that the course we removed is the course with longest
// duration.
class Solution {

public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int max_courses = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        sort(courses.begin(), courses.end(), [](const auto &lhs, const auto &rhs) {return lhs[1] < rhs[1];});
        int duration = 0;
        for (int i = 0; i < courses.size(); i++) {
            duration += courses[i][0];
            pq.push({courses[i][0], courses[i][1]});
            max_courses++;
            if (duration <= courses[i][1]) {
                continue;
            }

            while (!pq.empty()) {
                const auto [evicted_duration, _] = pq.top();
                pq.pop();
                duration -= evicted_duration;
                max_courses--;
                if (duration <= courses[i][1]) {
                    break;
                }
            }
        }
        return max_courses;
    }
};
