#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = INT_MIN, sum = 0;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            ans = max(ans, sum);
            sum = 0;
        } else
            sum += stoi(line);
    }

    cout << ans << endl;

    return 0;
}
