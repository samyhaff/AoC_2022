#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> read_input() {
    vector<vector<int>> forest;
    string line;

    while (getline(cin, line)) {
        forest.push_back(vector<int>());
        for (char c: line) {
            forest[forest.size() - 1].push_back(c - '0');
        }
    }

    return forest;
}

int solve(vector<vector<int>> forest) {
    unordered_set<int> visible;
    int n = forest.size(), m = forest[0].size();
    int max_height;

    for (int i = 0; i < n; i++) {
        max_height = INT_MIN;
        for (int j = 0; j < m; j++) {
            if (forest[i][j] > max_height) {
                max_height = forest[i][j];
                visible.insert(n * i + j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        max_height = INT_MIN;
        for (int j = m - 1; j >= 0; j--) {
            if (forest[i][j] > max_height) {
                max_height = forest[i][j];
                visible.insert(n * i + j);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        max_height = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (forest[i][j] > max_height) {
                max_height = forest[i][j];
                visible.insert(n * i + j);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        max_height = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (forest[i][j] > max_height) {
                max_height = forest[i][j];
                visible.insert(n * i + j);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (visible.find(n * i + j) != visible.end())
    //             cout << forest[i][j] << " ";
    //         else
    //             cout << "  ";
    //     }
    //     cout << endl;
    // }

    return visible.size();
}

int main() {
    vector<vector<int>> forest = read_input();
    int ans = solve(forest);

    cout << ans << endl;

    return 0;
}
