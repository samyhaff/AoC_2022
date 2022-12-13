#include <bits/stdc++.h>
#include <boost/functional/hash.hpp>

using namespace std;

#define N_KNOTS 10

void update(vector<pair<int, int>>& rope, char direction) {
    pair<int, int>& head = rope[0];
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

    for (int i = 1; i < N_KNOTS; i++) {
        auto& knot = rope[i], head = rope[i - 1];

        if (abs(head.first - knot.first) <= 1 && abs(head.second - knot.second) <= 1) {
            return;
        }
        else if (head.first == knot.first)
            knot.second += head.second > knot.second ? 1 : -1;
        else if (head.second == knot.second)
            knot.first += head.first > knot.first ? 1 : -1;
        else {
            knot.first += (head.first > knot.first) ? 1 : -1;
            knot.second += (head.second > knot.second) ? 1 : -1;
        }
    }
}

int solve() {
    int count;
    char direction;
    unordered_set<pair<int, int>, boost::hash<pair<int, int>>> set;
    vector<pair<int, int>> rope(N_KNOTS, {0, 0});

    set.insert(rope[N_KNOTS - 1]);
    while (cin >> direction >> count) {
        for (int i = 0; i < count; i++) {
            update(rope, direction);
            set.insert(rope[N_KNOTS - 1]);;
        }
    }

    return set.size();
}

int main() {
    int ans = solve();

    cout << ans << endl;

    return 0;
}
