#include <bits/stdc++.h>

using namespace std;

#define LENGTH 14

int main() {
    string input;
    unordered_set<char> set;

    getline(cin, input);
    for (int i = LENGTH; i < input.length(); i++) {
        set.clear();
        for (int j = i - LENGTH; j < i; j++)
            set.insert(input[j]);
        if (set.size() == LENGTH) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
