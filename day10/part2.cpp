#include <bits/stdc++.h>

using namespace std;

#define N_ROWS 6
#define N_COLS 40

void print_image() {
    string instruction;
    int value, x = 1, cycle = 1;
    vector<char> crt(N_ROWS * N_COLS);

    while (cin >> instruction) {
        crt[cycle - 1] = (abs(x - ((cycle - 1) % N_COLS)) <= 1) ? '#' : '.';
        if (instruction == "addx") {
            cin >> value;
            cycle++;
            crt[cycle - 1] = (abs(x - ((cycle - 1) % N_COLS)) <= 1) ? '#' : '.';
            x += value;
        }
        cycle++;
    }

    for (int i = 0; i < N_ROWS; i++) {
        for (int j = 0; j < N_COLS; j++)
            cout << crt[N_COLS * i + j];
        cout << endl;
    }
}

int main() {
    print_image();

    return 0;
}
