#include <bits/stdc++.h>

using namespace std;

enum cmp { SMALLER, EQUAL, BIGGER };

pair<string, string> get_value_and_rest(string list) {
    string value, rest;
    int brackets_count = 0;
    int i = 1;

    for (int j = 1; j < list.size(); j++) {
        if ((list[j] == ',' || list[j] == ']') && brackets_count == 0) {
            value = list.substr(i, j - i);
            rest = list.substr(j + 1, list.size() - j - 1);
            rest = rest.empty() ? " " : rest.insert(0, "[");
            break;
        }
        else if (list[j] == ']')
            brackets_count--;
        else if (list[j] == '[')
            brackets_count++;
    }

    return {value, rest};
}

cmp compare(string a, string b) {
    pair<string, string> pair_a = get_value_and_rest(a);
    pair<string, string> pair_b = get_value_and_rest(b);
    string value_a = pair_a.first;
    string value_b = pair_b.first;
    string rest_a = pair_a.second;
    string rest_b = pair_b.second;
    cmp res;

    if (value_a.empty() && !value_b.empty()) return SMALLER;
    else if (value_b.empty() && !value_a.empty()) return BIGGER;
    else if (value_a.empty() && value_b.empty()) return EQUAL;
    else if (value_a[0] != '[' && value_b[0] != '[') {
        if (stoi(value_a) < stoi(value_b)) return SMALLER;
        else if (stoi(value_a) > stoi(value_b)) return BIGGER;
        else if (rest_a.empty() && rest_b.empty()) return EQUAL;
        else return compare(rest_a, rest_b);
    }
    else if (value_a[0] == '[' && value_b[0] == '[')
        res = compare(value_a, value_b);
    else if (value_a[0] == '[' && value_b[0] != '[')
        res = compare(value_a, "[" + value_b + "]");
    else if (value_a[0] != '[' && value_b[0] == '[')
        res = compare("[" + value_a + "]", value_b);

    return (res != EQUAL) ? res : compare(rest_a, rest_b);
}

int solve() {
    vector<string> lists;
    string list;
    pair<int, int> pos = { 1, 1 };

    while (cin >> list)
        lists.push_back(list);
    lists.push_back("[[2]]");
    lists.push_back("[[6]]");

    for (string list: lists) {
        if (compare("[[2]]", list) == BIGGER) {
            pos.first++;
            cout << list << endl;
        }
        if (compare("[[6]]", list) == BIGGER) pos.second++;
    }

    cout << pos.first << " " << pos.second << endl;

    return pos.first * pos.second;
}

int main() {
    int ans = solve();

    cout << ans << endl;

    return 0;
}
