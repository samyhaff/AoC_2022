#include <bits/stdc++.h>

using namespace std;

bool overlap(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first && a.second >= b.first;
}

int main() {
    pair<int, int> a, b;
    string line;
    int ans = 0;

    while (getline(cin, line)) {
        sscanf(line.c_str(), "%d-%d,%d-%d", &a.first, &a.second, &b.first, &b.second);
        if (overlap(a, b) || overlap(b, a)) ans++;
    }

    cout << ans << endl;
    return 0;
}
