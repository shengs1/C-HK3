#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& list,int length) {
    length = list.size();
    int *ptr = list.data();
    int i,j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) { 
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int c = 0;  
    vector<int> list;

    while(c != 999) {
        cout << "Xin Moi Ban Nhap So: ";
        cin >> c;

        if(c == 999) {
            cout << "Chieu Dai Cua list: " << list.size() << endl;// in ra kích thuoc list
            break;  
        }

        list.push_back(c); //thêm số nhập vào danh sách
    }

    int chieudai;
    bubbleSort(list,chieudai); 

    cout << "***********************************" << endl;
    for (int i = 0; i < list.size(); ++i) {
        cout << "i: " << list[i] << " " << endl;
    }

    return 0;
}
