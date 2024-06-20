#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int nhiphantothapphan(string nhiphan) {
    int kq = 0;
    int n = nhiphan.length(); 

    for (int i = 0; i < n; ++i) {
        if (nhiphan[n - 1 - i] == '1') {
            kq = kq + 1 * pow(2, i);
        }
    }
    return kq;
}

int main() {
    string nhiphan;
    bool check;

    do {
        cout << "Vui long nhap so nhi phan can doi: " << endl;
        cin >> nhiphan;
        check = true;
        for (int i = 0; i < nhiphan.length(); ++i) {
            if (nhiphan[i] != '0' && nhiphan[i] != '1') {
                check = false;
                cout << "Nhap sai vui long nhap 0 or 1 " << endl;
                break;
            }
        }
    } while (!check);

    int n = nhiphan.length();
    int thapphan = nhiphantothapphan(nhiphan);

    cout << "Do dai cua chuoi " << nhiphan << " la: " << n << endl;
    cout << "Gia tri thap phan cua so nhi phan " << nhiphan << " la: " << thapphan << endl;

    return 0;
}
