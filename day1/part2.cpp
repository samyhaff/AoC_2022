#include <bits/stdc++.h>

#define TOP 3

using namespace std;

int main() {
    priority_queue<int> pq;
    string line;
    int sum = 0, ans = 0;

    while (getline(cin, line)) {
        if (line.empty()) {
            pq.push(sum);
            sum = 0;
        } else
            sum += stoi(line);
    }
    pq.push(sum);

    for (int i = 1; i <= TOP; i++) {
        ans += pq.top(); pq.pop();
    }

    cout << ans << endl;

    return 0;
}
