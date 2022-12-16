#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> read_input() {
    vector<vector<char>> map;
    string line;

    while (getline(cin, line)) {
        map.push_back(vector<char>());
        for (char c: line)
            map.end()[-1].push_back(c);
    }

    return map;
}

vector<pair<int, int>> find_points(vector<vector<char>>& map) {
    int n = map.size(), m = map[0].size();
    vector<pair<int, int>> points(2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'S') {
                points[0] = { i, j };
                map[i][j] = 'a';
            }
            else if (map[i][j] == 'E') {
                points[1] = { i, j };
                map[i][j] = 'z';
            }
        }
    }

    return points;
}

int bfs(const vector<vector<char>>& map, const vector<pair<int, int>>& points) {
    int n = map.size(), m = map[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> distances(n, vector<int>(m, 0));
    queue<pair<int, int>> queue;
    vector<pair<int, int>> directions = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, - 1 }};
    pair<int, int> current;
    pair<int, int> start = points[1];

    queue.push(start);
    visited[start.first][start.second] = true;
    distances[start.first][start.second] = 0;

    while (!queue.empty()) {
        current = queue.front(); queue.pop();
        if (map[current.first][current.second] == 'a')
            return distances[current.first][current.second];
        for (auto& dir: directions) {
            if (current.first + dir.first >= 0 && current.first + dir.first < n
            && current.second + dir.second >= 0 && current.second + dir.second < m
            && !visited[current.first + dir.first][current.second + dir.second]
            && map[current.first][current.second] - map[current.first + dir.first][current.second + dir.second] <= 1) {
                queue.push({current.first + dir.first, current.second + dir.second});
                visited[current.first + dir.first][current.second + dir.second] = true;
                distances[current.first + dir.first][current.second + dir.second] = distances[current.first][current.second] + 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<char>> map = read_input();
    vector<pair<int, int>> points = find_points(map);
    int ans = bfs(map, points);

    cout << ans << endl;

    return 0;
}
