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

vector<vector<char>> make_map(const vector<vector<pair<int, int>>>& lines) {
    auto limits = find_limits(lines);
    vector<vector<char>> map(limits.second + 1, vector<char>(limits.first + 1, '.'));
    pair<int, int> direction, coordinates;

    for (const auto& line: lines) {
        for (int i = 0; i < line.size() - 1; i++) {
            direction = (line[i].first == line[i + 1].first)
                ? (line[i].second < line[i + 1].second ? make_pair(0, 1)
                                                       : make_pair(0, -1))
                : (line[i].first < line[i + 1].first ? make_pair(1, 0)
                                                     : make_pair(-1, 0));
            coordinates = line[i];
            map[coordinates.second][coordinates.first] = '#';
            while (coordinates != line[i + 1]) {
                coordinates = { coordinates.first + direction.first,
                                coordinates.second + direction.second };
                map[coordinates.second][coordinates.first] = '#';
            }
        }
    }

    return map;
}

void print_map(const vector<vector<char>>& map) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> lines = read_input();
    vector<vector<char>> map = make_map(lines);
    print_map(map);

    return 0;
}
