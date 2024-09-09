#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

bool gameover;
const int width = 20;
const int height = 17;
int x, y, fruitX, fruitY, score;
vector<int> tailX, tailY; // Toa độ của đuôi rắn
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    tailX.clear();
    tailY.clear();
}

void Draw() {
    system("cls"); // Dùng "clear" cho Linux
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "*";
            else if (i == fruitY && j == fruitX)
                cout << "%";
            else {
                bool print = false;
                for (int k = 0; k < tailX.size(); k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "*";
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover = true;
                break;
        }
    }
}

void Algorithm() {
    int prevX = x;
    int prevY = y;
    int prev2X, prev2Y;

    for (size_t i = 0; i < tailX.size(); i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (size_t i = 0; i < tailX.size(); i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tailX.push_back(x);
        tailY.push_back(y);
    }
}

int main() {
    Setup();
    while (!gameover) {
        Draw();
        Input();
        Algorithm();
        this_thread::sleep_for(chrono::milliseconds(200)); // Thêm thời gian chờ để game không quá nhanh
    }
    return 0;
}
