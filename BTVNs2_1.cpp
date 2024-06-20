#include <iostream>


using namespace std;

int main () {

    char a[38]="Hoc, hoc nua, hoc mai. Co chi thi len";
    char *ptr;
    int dem = 0;
    ptr = a;

    for (int i = 0; i < 38; i++)
    {
        if (ptr[i] == 'i'){
            ptr[i] = 'I';
        }

    }

    cout <<"kq sao khi doi: "<< a << endl;
    
    

    return 0;
}
