#include <bits/stdc++.h>

using namespace std;

const unordered_set<int> cycles = { 20, 60, 100, 100, 140, 180, 220 };

int solve() {
    string instruction;
    int value, x = 1, cycle = 1, total_signal_strength = 0;

    while (cin >> instruction) {
        if (cycles.find(cycle) != cycles.end())
            total_signal_strength += x * cycle;
        if (instruction == "addx") {
            cin >> value;
            cycle++;
            if (cycles.find(cycle) != cycles.end())
                total_signal_strength += x * cycle;
            x += value;
        }
        cycle++;
    }

    return total_signal_strength;
}

int main() {
    int ans = solve();

    cout << ans << endl;

    return 0;
}
