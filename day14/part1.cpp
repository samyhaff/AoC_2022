#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> read_input() {
    vector<vector<pair<int, int>>> lines;
    string line, word;
    pair<int, int> coordinates;
    stringstream ss;

    while (getline(cin, line)) {
        lines.push_back(vector<pair<int,int>>());
        ss.clear(); ss.str(line);
        while (ss >> word) {
            sscanf(word.c_str(), "%d,%d", &coordinates.first, &coordinates.second);
            if (ss.peek() != EOF)
                ss >> word;
            lines.back().push_back(coordinates);
        }
    }

    return lines;
}

pair<int, int> find_limits(const vector<vector<pair<int, int>>>& lines) {
    pair<int, int> limits = { 0, 0 };
    for (auto& line: lines) {
        for (auto& coordinates: line) {
            if (coordinates.first > limits.first) limits.first = coordinates.first;
            if (coordinates.second > limits.second) limits.second = coordinates.second;
        }
    }

    return limits;
}

int main() {
    vector<vector<pair<int, int>>> lines = read_input();
    pair<int, int> limits = find_limits(lines);

    cout << limits.first << " " << limits.second << endl;

    return 0;
}
