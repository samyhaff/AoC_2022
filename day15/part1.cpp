#include <bits/stdc++.h>

using namespace std;

int solve(int row) {
    string line;
    pair<int, int> sensor, beacon;
    int distance, x;
    unordered_set<int> x_set, beacons_set;

    while (getline(cin, line)) {
        sscanf(line.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d",
               &sensor.first, &sensor.second, &beacon.first, &beacon.second);

        distance = abs(sensor.first - beacon.first) + abs(sensor.second - beacon.second);
        if (beacon.second == row)
            beacons_set.insert(beacon.first);

        for (x = abs(row - sensor.second) - distance + sensor.first;
            x <= distance - abs(row - sensor.second) + sensor.first;
            x++)
            x_set.insert(x);
    }

    for (int x: beacons_set) {
        if (x_set.find(x) != x_set.end())
            x_set.erase(x);
    }

    return x_set.size();
}

int main() {
    int ans = solve(2000000);

    cout << ans << endl;

    return 0;
}
