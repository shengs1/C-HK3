#include <iostream>
#include <cstring>
using namespace std;

const int MAXHS = 10;  
const int MAXLEN = 50;

int main() {
    char ds[MAXHS][MAXLEN]; 
    char *ptr[MAXHS]; 
    int i,j;    

    cout << "Nhap ten hoc sinh (Nhap '0' de ket thuc):"<<endl;

    int count = 0;
    while (count < MAXHS) {
        cout << "Nhap ten hoc sinh thu " << count + 1 << ": ";
        cin >> ds[count]; 

        if (strcmp(ds[count], "0") == 0) 
            break;

        ++count;
    }

 
    for (i = 0; i < count; ++i) {
        ptr[i] = ds[i];
    }

   
    for (i = 0; i < count - 1; ++i) {
        for (j = i + 1; j < count; ++j) {
            if (strcmp(ptr[i], ptr[j]) > 0) {
                char *tmp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tmp;
            }
        }
    }


    cout << "Danh sach hoc sinh truoc khi sap xep:"<<endl;
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ": " << ds[i] << endl;
    }

    cout << "Danh sach hoc sinh da sap xep theo thu tu ABC:"<<endl;
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ": " << ptr[i] << endl;
    }

    return 0;
}
