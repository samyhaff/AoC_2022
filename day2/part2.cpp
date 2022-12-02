#include <bits/stdc++.h>

using namespace std;

/*
A, X: rock
B, Y: paper
C, Z: scissors
*/

int main() {
    int total_score = 0, score;
    char opponent_choice, outcome, my_choice;
    string line;
    unordered_map<char, int> selection_score;
    unordered_map<char, char> win_table, loss_table;

    selection_score = {{'X', 1}, {'Y', 2}, {'Z', 3}};
    win_table = {{'A', 'Y'}, {'B', 'Z'}, {'C', 'X'}};
    loss_table = {{'A', 'Z'}, {'B', 'X'}, {'C', 'Y'}};

    while (cin >> opponent_choice >> outcome) {
        if (outcome == 'X') {
            my_choice = loss_table[opponent_choice];
            score = 0;
        } else if (outcome == 'Y') {
            my_choice = 'X' + opponent_choice - 'A';
            score = 3;
        } else {
            my_choice = win_table[opponent_choice];
            score = 6;
        }
        score += selection_score[my_choice];
        total_score += score;
    }

    cout << total_score << endl;
}
