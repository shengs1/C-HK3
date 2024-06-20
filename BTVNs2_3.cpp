#include <iostream>
using namespace std;

const int hang = 3;
const int cot = 3;

int main() {
    int mt[hang][cot];

    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            cout << "Nhap hang " << i + 1 << ", cot " << j + 1 << ": ";
            cin >> mt[i][j];
        }
    }

    cout << "Ma tran da nhap la:" << endl;
    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            cout << mt[i][j] << " ";
        }
        cout << endl;
    }

    int tong = 0;
    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            tong += mt[i][j];
        }
    }

    cout << "tong cac phan tu la: " << tong << endl;

    return 0;
}
