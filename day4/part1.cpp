#include <bits/stdc++.h>

using namespace std;

bool is_included(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first && a.second >= b.second;
}

int main() {
    pair<int, int> a, b;
    string line;
    int ans = 0;

    while (getline(cin, line)) {
        sscanf(line.c_str(), "%d-%d,%d-%d", &a.first, &a.second, &b.first, &b.second);
        cout << a.first << endl;
        if (is_included(a, b) || is_included(b, a)) ans++;
    }

    cout << ans << endl;

    return 0;
}
