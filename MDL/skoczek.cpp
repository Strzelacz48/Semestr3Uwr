#include <iostream>
using namespace std;

const int N = 5;

int board[N][N];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solve(int x, int y, int move) {
    board[x][y] = move;
    if (move == N*N) {
        printBoard();
        return true;
    }
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY) && solve(newX, newY, move+1)) {
            return true;
        }
    }
    board[x][y] = 0;
    return false;
}

int main() {
    int startX, startY;
    cout << "Enter starting position (x y): ";
    cin >> startX >> startY;
    cout << "Possible knight's moves:" << endl;
    solve(startX, startY, 1);
    return 0;
}