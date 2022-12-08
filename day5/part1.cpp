#include <bits/stdtr1c++.h>

#define N_STACKS 9
#define HEIGHT 8

using namespace std;

vector<vector<char>> read_input() {
    string line;
    char crate;
    vector<vector<char>> stacks(N_STACKS, vector<char>());

    for (int i = 0; i < HEIGHT; i++) {
        getline(cin, line);
        for (int i = 0; i < line.length() / 4; i++) {
            if (line[4 * i + 1] != ' ')
                stacks[i].push_back(line[4 * i + 1]);
        }
    }

    for (auto& stack: stacks)
        reverse(stack.begin(), stack.end());

    return stacks;
}

int main() {
    vector<vector<char>> stacks = read_input();
    for (auto& stack: stacks) {
        for (char crate: stack)
            cout << crate << " ";
        cout << endl;
    }

    return 0;
}
