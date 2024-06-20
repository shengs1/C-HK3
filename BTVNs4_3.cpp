#include <iostream>
using namespace std;

int binary_search(int a[], int n, int x){
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2; // tinh phan tu o giua mang 
        if (a[m] == x) 
            return m;
        if (a[m] < x)
            l = m + 1; // tim kiem phan tu ben phai 
        else
            r = m - 1; // tim kiem phan tu ben trai
    }
    return -1;
}

int main(){
    int arr[] ={1,4,2,3,6,5,8,9,7};
    int n = 9;
    //bubblesort từ bé đến lớn
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout <<"mang sau khi sap xep theo thu tu tang dan"<<endl;
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": " << arr[i] << endl;
    }
    
    int sbk;
    do{
        cout <<"Nhap 1 so bat ki khac 0"<<endl;
        cin >> sbk;
        if(sbk <= 0){
            cout <<"Nhap lai so khac 0 "<<endl;
        }
    }while(sbk <= 0);

    int result = binary_search(arr, n, sbk);
    if(result != -1){
        cout << "Vi tri cua so la: " << result << endl;
    }
    else {
        cout << "Khong tiem thay"<<endl;
    }

    return 0;
}