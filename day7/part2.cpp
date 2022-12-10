#include <bits/stdc++.h>

using namespace std;

#define TOTAL_SPACE  70000000
#define NEEDED_SPACE 30000000

struct Directory {
    Directory *parent = nullptr;
    int files_size = 0;
    unordered_map<string, Directory *> children = unordered_map<string, Directory *>();
};

Directory *get_filesystem() {
    string token;
    Directory *filesystem = new Directory;
    Directory *current = filesystem;

    filesystem->children["/"] = new Directory;
    while (cin >> token) {
        if (token == "$") {
            continue;
        } else if (token == "cd") {
            cin >> token;
            if (token == "..")
                current = current->parent;
            else
                current = current->children[token];
        } else if (token == "ls") {
            while (cin >> token && token != "$") {
                if (token == "dir") {
                    cin >> token;
                    current->children[token] = new Directory;
                    current->children[token]->parent = current;
                } else {
                    current->files_size += stoi(token);
                    cin >> token;
                }
            }
        }
    }

    return filesystem;
}

class Solve {
public:
    vector<int> sizes = vector<int>();
    int ans = INT_MAX;

    int get_sizes(Directory *dir){
        int size = 0;
        if (dir->children.empty()) {
            size = dir->files_size;
        } else {
            size += dir->files_size;
            for (auto entry: dir->children)
                size += get_sizes(entry.second);
        }
        sizes.push_back(size);
        return size;
    }

    void operator()(Directory *filesystem) {
        get_sizes(filesystem);
        int used_space = sizes[sizes.size() - 1];
        for (int size: sizes) {
            if (TOTAL_SPACE - used_space + size >= NEEDED_SPACE && size < ans)
                ans = size;
        }
    }
};

int main() {
    Directory *filesystem;
    Solve solve;

    filesystem = get_filesystem();
    solve(filesystem);
    cout << solve.ans << endl;

    return 0;
}
