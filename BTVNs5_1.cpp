#include <iostream>
#include <cstring> 
using namespace std;

void bubbleSort(char ten[][8], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (strcmp(ten[j], ten[j + 1]) > 0){ // so sánh chuỗi thứ nhất vs chuỗi thứ 2 (j + 1)
                char temp[8];
                strcpy(temp, ten[j]);
                strcpy(ten[j], ten[j + 1]);
                strcpy(ten[j + 1], temp);
                //swap(ten[j], ten[j+1]); có thể dùng dùng hàm swap đỗi ch
            }
        }
    }  
}

void selectionSort(char ten[][8], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ten[j], ten[min_idx]) < 0) {
                min_idx = j;
                //swap(ten[min_idx], ten[i]); có thể dùng hàm swap để đỗi chổ
            }
        }
        // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        if (min_idx != i) {
            char temp[8];
            strcpy(temp, ten[i]);
            strcpy(ten[i], ten[min_idx]);
            strcpy(ten[min_idx], temp);
        }
    }
}

void insertionSort(char ten[][8], int n) {
    for (int i = 1; i < n; i++) {
        char key[8];
        strcpy(key, ten[i]);
        int j = i - 1;
        // Di chuyển các phần tử lớn hơn key đến vị trí phía sau
        while (j >= 0 && strcmp(ten[j], key) > 0) {
            strcpy(ten[j + 1], ten[j]);
            j = j - 1;
        }
        strcpy(ten[j + 1], key);
    }
}


void printArray(const char ten[][8], int n, const char* sortType) {
    cout << sortType << ": ";
    for (int i = 0; i < n; i++)
        cout << ten[i] << " ";
    cout << endl;
}

int CheckTen_Vitri(char ten[][8], int n, const char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ten[i], name) == 0) {
            return i + 1;
        }
    }
    return -1;
}

#define MAX 8

int main() {
    //Task 1
    char ten[][MAX] = {"Linh", "Yen", "Hong", "Dao", "Mai", "Truc", "Mong", "Hung"};
    int n = sizeof(ten) / sizeof(ten[0]);
    
    bubbleSort(ten, n);
    printArray(ten, n, "bubbleSort");
    
    cout << "************************" << endl;
    // Đặt mảng về trạng thái ban đầu
    char ten2[][MAX] = {"Linh", "Yen", "Hong", "Dao", "Mai", "Truc", "Mong", "Hung"};
    selectionSort(ten2, n);
    printArray(ten2, n, "selectionSort");
    
    cout << "************************" << endl;
    char ten3[][MAX] = {"Linh", "Yen", "Hong", "Dao", "Mai", "Truc", "Mong", "Hung"};
    insertionSort(ten3, n);
    printArray(ten3, n, "insertionSort");

    //Task 2
    char Checkname[MAX];
    cout <<"Nhap 1 ten bat ki: "<<endl;
    cin >> Checkname;

    int index = CheckTen_Vitri(ten, n, Checkname);

    if (index != -1)
    {
        cout <<"Ten: "<< Checkname << " co trong danh sach tai vi tri "<< index <<endl;
    }
    else 
    {
        cout << Checkname << " khong co trong danh sach" <<endl;
    }   


    return 0;
}