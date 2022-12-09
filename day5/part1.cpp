#include <bits/stdtr1c++.h>

using namespace std;

#define N_STACKS 9
#define HEIGHT 8

struct instruction {
    int count;
    int from;
    int to;
};

vector<vector<char>> read_stacks() {
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

vector<instruction> get_instructions() {
    string line, word;
    vector<instruction> instructions;
    int count, from, to;
    instruction instruction;

    while (getline(cin, line)) {
        stringstream s(line);
        s >> word >> count >> word >> from >> word >> to;
        instruction = { .count = count, .from = from, .to = to };
        instructions.push_back(instruction);
    }

    return instructions;
}

int main() {
    vector<vector<char>> stacks;
    string line;
    vector<instruction> instructions;

    stacks = read_stacks();
    getline(cin, line); getline(cin, line);
    instructions = get_instructions();
    for (auto instr: instructions)
        cout << instr.count << " " << instr.from << " " << instr.to << endl;

    return 0;
}
