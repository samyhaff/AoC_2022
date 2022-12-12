#include <bits/stdc++.h>
#include <boost/functional/hash.hpp>

using namespace std;

void update(pair<int, int>& head, pair<int, int>& tail, char direction) {
    switch (direction) {
        case 'R':
            head.first++;
            break;
        case 'L':
            head.first--;
            break;
        case 'U':
            head.second++;
            break;
        case 'D':
            head.second--;
            break;
    }

    if (abs(head.first - tail.first) <= 1 && abs(head.second - tail.second) <= 1) {
        return;
    }
    else if (head.first == tail.first)
        tail.second += head.second > tail.second ? 1 : -1;
    else if (head.second == tail.second)
        tail.first += head.first > tail.first ? 1 : -1;
    else {
        tail.first += (head.first > tail.first) ? 1 : -1;
        tail.second += (head.second > tail.second) ? 1 : -1;
    }
}

int solve() {
    char direction;
    int count;
    unordered_set<pair<int, int>, boost::hash<pair<int, int>>> set;
    pair<int, int> head, tail;

    head = tail = { 0, 0 };
    set.insert(tail);
    while (cin >> direction >> count) {
        for (int i = 0; i < count; i++) {
            update(head, tail, direction);
            set.insert(tail);
        }
    }

    return set.size();
}

int main() {
    int ans = solve();

    cout << ans << endl;

    return 0;
}
