#include <bits/stdc++.h>

using namespace std;

int main() {
    string rucksacks[3];
    int ans = 0;
    unordered_map<char, int> map;
    unordered_set<char> set;

    while (cin >> rucksacks[0] >> rucksacks[1] >> rucksacks[2]) {
        map.clear();
        for (int i = 0; i < 3; i++) {
            set.clear();
            for (char item: rucksacks[i]) set.insert(item);
            for (char item: set) {
                if (map.find(item) == map.end()) {
                    map[item] = 1;
                } else {
                    map[item]++;
                    if (map[item] == 3) {
                        ans += (item > 'a') ? item - 'a' + 1 : item - 'A' + 27;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
