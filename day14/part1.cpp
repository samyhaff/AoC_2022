#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> read_input() {
    vector<vector<pair<int, int>>> lines;
    string line, word;
    pair<int, int> coordinates;
    stringstream ss;

    while (getline(cin, line)) {
        lines.push_back(vector<pair<int,int>>());
        ss.str(line);
        while (ss >> word) {
            sscanf(word.c_str(), "%d,%d", &coordinates.first, &coordinates.second);
            if (ss.peek() != EOF)
                ss >> word;
            lines.back().push_back(coordinates);
        }
    }

    return lines;
}

int main() {
    vector<vector<pair<int, int>>> lines = read_input();

    return 0;
}
