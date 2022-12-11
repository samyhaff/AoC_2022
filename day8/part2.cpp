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

int get_score(const vector<vector<int>>& forest, int i, int j, int di, int dj) {
    int n = forest.size(), m = forest[0].size();
    int score = 0;
    int height = forest[i][j];

    while (true) {
        score++;
        i += di; j += dj;
        if (i >= n - 1 || j >= m - 1 || i <= 0 || j <= 0 || forest[i][j] >= height) break;
    }

    return score;
}

int solve(const vector<vector<int>>& forest) {
    int n = forest.size(), m = forest[0].size();
    int max_score = INT_MIN;
    int score_up, score_down, score_left, score_right, score;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            score_up = get_score(forest, i, j, -1, 0);
            score_down = get_score(forest, i, j, 1, 0);
            score_left = get_score(forest, i, j, 0, -1);
            score_right = get_score(forest, i, j, 0, 1);
            score = score_up * score_down * score_left * score_right;
            if (score > max_score)
                max_score = score;
        }
    }

    return max_score;
}

int main() {
    vector<vector<int>> forest = read_input();
    int ans = solve(forest);

    cout << ans << endl;

    return 0;
}
