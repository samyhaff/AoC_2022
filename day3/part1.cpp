#include <bits/stdc++.h>

using namespace std;

int main() {
    string rucksack;
    int n, ans = 0;

    while (getline(cin, rucksack)) {
        n = rucksack.length();
        unordered_set<char> set;
        for (auto it = rucksack.begin(); it < rucksack.begin() + n / 2; it++)
            set.insert(*it);
        for (auto it = rucksack.begin() + n / 2; it != rucksack.end(); it++) {
            if (set.find(*it) != set.end()) {
                ans += (*it > 'a') ? *it - 'a' + 1 : *it - 'A' + 27;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
