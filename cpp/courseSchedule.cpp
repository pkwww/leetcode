#include <vector>
#include <queue>
#include <list>
using namespace std;


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // bfs
    vector<int> in_d(numCourses);
    vector<vector<int>> outs(numCourses);
    for (auto& p: prerequisites) {
        int x = p[0];
        int y = p[1];
        in_d[y]++;
        outs[x].push_back(y);
    }
    
    queue<int, list<int>> q;
    for (int i = 0; i < numCourses; i++) {
        if (in_d[i] == 0) {
            q.push(i);
        }
    }
    
    int visited_count = 0;
    while (!q.empty()) {
        visited_count++;
        int curr = q.front();
        q.pop();
        vector<int> out = outs[curr];
        for (int neibour: out) {
            in_d[neibour]--;
            if (in_d[neibour] == 0) {
                q.push(neibour);
            }
        }
    }
    return visited_count == numCourses;
}

// color: virgin=0, visiting=1, visited=2
void dfs(int u, vector<int>& color, vector<vector<int>>& outs, bool& detected) {
    color[u] = 1;
    for (int v: outs[u]) {
        if (color[v] == 0) {
            dfs(v, color, outs, detected);
        } else if (color[v] == 1) {
            detected = true;
        }
    }
    color[u] = 2;
}

bool canFinishDfs(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> color(numCourses);
    vector<vector<int>> outs(numCourses);
    for (auto& p : prerequisites) {
        int x = p[0];
        int y = p[1];
        outs[x].push_back(y);
    }

    bool detected = false;
    for (int i = 0; i < numCourses; ++i) {
        if (color[i] == 0) {
            dfs(i, color, outs, detected);
        }
    }
    return !detected;
}
