#include <iostream>
using namespace std;

void doicoso10sang2(int so) {
    if (so < 2) {
        cout << so;
    }
    else{
    doicoso10sang2(so / 2);
    cout << so % 2;
    }
}
void doicoso10sang8(int so)
{
    if (so < 8) {
        cout << so;
    }
    else{
    doicoso10sang8(so / 8);
    cout << so % 8;
    }
}
void doicoso10sang16(int so)
{
    if (so < 16) 
    {
        if (so < 10)
            cout << so;
        else
            cout << (char)('A' + so - 10);
    } 
    else {
        doicoso10sang16(so / 16); 
        int sodu = so % 16; 
        if (sodu < 10)
            cout << sodu;
        else
            cout << (char)('A' + sodu - 10);
    }
}

int main()
{
    cout << "Xin moi nhap lua chon sau: " << endl;
    cout << "1. Co so 10 sang co so 2." << endl;
    cout << "2. Co so 10 sang co so 8." << endl;
    cout << "3. Co so 10 sang co so 16." << endl; 

    int option=6;
    while (option > 4)
    {
    cout << "Xin moi nhap: ";
    cin >> option;
    }
    int so;

    switch (option)
    {
        case 1:
        cout << "Xin moi nhap so can doi: " << endl;
        cin >> so;
        cout << "so nhi phan cua so " << so <<" la: "<<endl;
        doicoso10sang2(so);
        break;
    case 2:
        {
        cout << "Xin moi nhap so can doi: "<< endl;
        cin >> so;
        cout << "so bat phan cua so " << so <<" la: "<<endl;
        doicoso10sang8(so);
        break;
        }
    case 3:
        {
        cout << "Xin moi nhap so can doi: "<< endl;
        cin >> so;
        cout << "so thap luc phan cua so " << so <<" la: "<<endl;
        doicoso10sang16(so);
        break;
        }
    default: 
        {
        break;
        }
    }
    return 0;
}