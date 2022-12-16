#include <bits/stdc++.h>

using namespace std;

vector<string> get_values(string list) {
    vector<string> values;
    int brackets_count = 0;
    int i = 1;

    for (int j = 1; j < list.size(); j++) {
        if ((list[j] == ',' || list[j] == ']') && brackets_count == 0) {
            values.push_back(list.substr(i, j - i));
            cout << list.substr(i, j - i) << " ";
            i = j + 1;
        }
        else if (list[j] == ']')
            brackets_count--;
        else if (list[j] == '[')
            brackets_count++;
    }

    cout << endl;
    return values;
}

// bool compare(string a, string b) {
//     if (a[0] != '[' && b[0] != '[')
//         return stoi(a) <= stoi(b);
//     else if (a[0] != '[' && b[0] == '[')
//         return compare('[' + a + ']', b);
//     else if (a[0] == '[' && b[0] != '[')
//         return compare(a, '[' + b + ']');
//     else {
//
//     }
// }

int main() {
    string a, b;

    while (cin >> a >> b) {
        get_values(a);
        get_values(b);
    }

    return 0;
}
