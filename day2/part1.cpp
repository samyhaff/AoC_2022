#include <bits/stdc++.h>

using namespace std;

/*
A, X: rock
B, Y: paper
C, Z: scissors
*/

int main() {
    int total_score = 0, score;
    char opponent_choice, my_choice;
    string line;
    unordered_map<char, int> selection_score;
    unordered_map<char, char> win_table;

    selection_score = {{'X', 1}, {'Y', 2}, {'Z', 3}};
    win_table = {{'A', 'Y'}, {'B', 'Z'}, {'C', 'X'}};

    while (cin >> opponent_choice >> my_choice) {
        score = selection_score[my_choice];
        if (my_choice == win_table[opponent_choice]) score += 6;
        else if (my_choice - 'X' == opponent_choice - 'A') score += 3;
        total_score += score;
    }

    cout << total_score << endl;
}
