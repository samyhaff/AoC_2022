#include <bits/stdc++.h>

using namespace std;

const unsigned long long int COMMON_MULTIPLE = 7 * 11 * 13 * 3 * 17 * 2 * 5 * 19;

struct Monkey {
    vector<unsigned long long int> list;
    function<unsigned long long int(unsigned long long int)> operation;
    function<bool(unsigned long long int)> test;
    vector<int> recipients; // (false, true)
    unsigned long long int nb_inspections = 0;
};

vector<Monkey> init() {
    vector<Monkey> monkeys(8);

    monkeys[0].list = { 63, 57 };
    monkeys[1].list = { 82, 66, 87, 78, 77, 92, 83 };
    monkeys[2].list = { 97, 53, 53, 85, 58, 54 };
    monkeys[3].list = { 50 };
    monkeys[4].list = { 64, 69, 52, 65, 73 };
    monkeys[5].list = { 57, 91, 65 };
    monkeys[6].list = { 67, 91, 84, 78, 60, 69, 99, 83 };
    monkeys[7].list = { 58, 78, 69, 65 };

    monkeys[0].operation = [](unsigned long long int old) { return old * 11; };
    monkeys[1].operation = [](unsigned long long int old) { return old + 1; };
    monkeys[2].operation = [](unsigned long long int old) { return old * 7; };
    monkeys[3].operation = [](unsigned long long int old) { return old + 3; };
    monkeys[4].operation = [](unsigned long long int old) { return old + 6; };
    monkeys[5].operation = [](unsigned long long int old) { return old + 5; };
    monkeys[6].operation = [](unsigned long long int old) { return old * old; };
    monkeys[7].operation = [](unsigned long long int old) { return old + 7; };

    monkeys[0].test = [](unsigned long long int level) { return level % 7 == 0; };
    monkeys[1].test = [](unsigned long long int level) { return level % 11 == 0; };
    monkeys[2].test = [](unsigned long long int level) { return level % 13 == 0; };
    monkeys[3].test = [](unsigned long long int level) { return level % 3 == 0; };
    monkeys[4].test = [](unsigned long long int level) { return level % 17 == 0; };
    monkeys[5].test = [](unsigned long long int level) { return level % 2 == 0; };
    monkeys[6].test = [](unsigned long long int level) { return level % 5 == 0; };
    monkeys[7].test = [](unsigned long long int level) { return level % 19 == 0; };

    monkeys[0].recipients = { 2, 6 };
    monkeys[1].recipients = { 0, 5 };
    monkeys[2].recipients = { 3, 4 };
    monkeys[3].recipients = { 7, 1 };
    monkeys[4].recipients = { 7, 3 };
    monkeys[5].recipients = { 6, 0 };
    monkeys[6].recipients = { 4, 2 };
    monkeys[7].recipients = { 1, 5 };

    return monkeys;
}

void run_rounds(vector<Monkey>& monkeys, int nb_rounds) {
    int recipient;
    unsigned long long int new_level;

    for (int i = 0; i < nb_rounds; i++) {
        for (auto& monkey: monkeys) {
            monkey.nb_inspections += monkey.list.size();
            for (auto old_level: monkey.list) {
                new_level = monkey.operation(old_level) % COMMON_MULTIPLE;
                recipient = monkey.recipients[monkey.test(new_level)];
                monkeys[recipient].list.push_back(new_level);
            }
            monkey.list = {};
        }
    }
}

unsigned long long int solve(vector<Monkey>& monkeys, int nb_rounds) {
    unsigned long long int ans;
    vector<unsigned long long int> nb_inspections;

    run_rounds(monkeys, nb_rounds);

    for (auto& monkey: monkeys)
        nb_inspections.push_back(monkey.nb_inspections);
    sort(nb_inspections.begin(), nb_inspections.end());
    ans = nb_inspections.end()[-1] * nb_inspections.end()[-2];

    return ans;
}

int main() {
    vector<Monkey> monkeys = init();
    unsigned long long int ans = solve(monkeys, 10000);

    cout << ans << endl;

    return 0;
}
