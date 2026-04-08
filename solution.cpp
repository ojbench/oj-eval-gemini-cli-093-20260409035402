#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int map[10][10];
    int start_x = -1, start_y = -1;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (!(cin >> map[i][j])) return 0;
            if (map[i][j] == 4) {
                start_x = i;
                start_y = j;
            }
        }
    }

    int x = start_x;
    int y = start_y;
    int dir = 0; // 0: UP, 1: RIGHT, 2: DOWN, 3: LEFT
    int score = 0;

    bool visited[10][10][4];
    memset(visited, 0, sizeof(visited));
    visited[x][y][dir] = true;

    while (true) {
        int next_dir = -1;
        int next_x = -1, next_y = -1;

        int dirs_to_check[] = { (dir + 1) % 4, dir, (dir + 3) % 4, (dir + 2) % 4 };

        for (int i = 0; i < 4; ++i) {
            int ndir = dirs_to_check[i];
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            
            if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && map[nx][ny] != 0) {
                next_dir = ndir;
                next_x = nx;
                next_y = ny;
                break;
            }
        }

        if (next_dir == -1) {
            cout << "Silly Pacman" << endl;
            return 0;
        }

        x = next_x;
        y = next_y;
        dir = next_dir;

        if (map[x][y] == 3) {
            score -= 500;
            cout << score << endl;
            return 0;
        } else if (map[x][y] == 2) {
            score += 2;
            map[x][y] = 1;
            memset(visited, 0, sizeof(visited));
            visited[x][y][dir] = true;
        } else {
            if (visited[x][y][dir]) {
                cout << "Silly Pacman" << endl;
                return 0;
            }
            visited[x][y][dir] = true;
        }
    }

    return 0;
}
