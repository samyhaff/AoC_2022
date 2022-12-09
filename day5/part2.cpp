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
        for (int i = 0; i < line.length() / 4 + 1; i++) {
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
        instruction = { .count = count, .from = from - 1, .to = to - 1 };
        instructions.push_back(instruction);
    }

    return instructions;
}

void process_intructions(vector<vector<char>>& stacks,
                         vector<instruction>& instructions) {
    int val;
    stack<char> transfer_stack;
    for (auto& instruction: instructions) {
        for (int i = 0; i < instruction.count; i++) {
            val = stacks[instruction.from].back(); stacks[instruction.from].pop_back();
            transfer_stack.push(val);
        }
        while (!transfer_stack.empty()) {
            val = transfer_stack.top(); transfer_stack.pop();
            stacks[instruction.to].push_back(val);
        }
    }
}

int main() {
    vector<vector<char>> stacks;
    string line;
    vector<instruction> instructions;
    string output;

    stacks = read_stacks();
    getline(cin, line); getline(cin, line);
    instructions = get_instructions();
    process_intructions(stacks, instructions);
    for (auto& stack: stacks)
        output.push_back(stack.back());

    cout << output << endl;

    return 0;
}
