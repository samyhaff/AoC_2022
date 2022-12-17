#include <bits/stdc++.h>

using namespace std;

pair<string, string> get_value_and_rest(string list) {
    string value, rest;
    int brackets_count = 0;
    int i = 1;

    for (int j = 1; j < list.size(); j++) {
        if ((list[j] == ',' || list[j] == ']') && brackets_count == 0) {
            value = list.substr(i, j - i);
            rest = list.substr(j + 1, list.size() - j - 1);
            rest = rest.empty() ? "" : rest.insert(0, "[");
            break;
        }
        else if (list[j] == ']')
            brackets_count--;
        else if (list[j] == '[')
            brackets_count++;
    }

    return {value, rest};
}

bool compare(string a, string b) {
    pair<string, string> pair_a = get_value_and_rest(a);
    pair<string, string> pair_b = get_value_and_rest(b);
    string value_a = pair_a.first;
    string value_b = pair_b.first;
    string rest_a = pair_a.second;
    string rest_b = pair_b.second;

    if (value_a.empty()) return true;
    if (value_b.empty()) return false;
    if (value_a[0] != '[' && value_b[0] != '[') {
        if (stoi(value_a) < stoi(value_b)) return true;
        else if (stoi(value_a) > stoi(value_b)) return false;
        else return compare(rest_a, rest_b);
    }
    if (value_a[0] == '[' && value_b[0] == '[' && !compare(value_a, value_b))
        return false;
    else if (value_a[0] == '[' && value_b[0] != '[' && !compare(value_a, "[" + value_b + "]"))
        return false;
    else if (value_a[0] != '[' && value_b[0] == '[' && !compare("[" + value_a + "]", value_b))
        return false;

    return compare(rest_a, rest_b);
}

int main() {
    string a, b;
    int ans = 0;
    int i = 1;

    while (cin >> a >> b) {
        if (compare(a, b)) {
            ans += i;
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}
