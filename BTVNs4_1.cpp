#include <iostream>

using namespace std;


int main() {
    int m,n;
    cout <<"Xin moi nhap hang: "<<endl;
    cin >> m;
    cout <<"Xin moi nhap cot: "<<endl;
    cin >> n;

    int *A = new int[m*n];
    for (int i = 0; i < m*n; i++)
    {
        cout <<"Xin moi nhap phan tu: "<<i<<": "<<endl;
        cin >>A[i];
    }
    for (int i=0; i < m; i++){
        for (int j=0; j<n; j++){
            cout <<A[i*n+j]<<": ";
        }
        cout << endl;
    }
    delete[] A;
    cout <<"Cach Two ********************************************"<<endl;
    int R, C;
    cout << "Xin moi nhap hang: ";
    cin >> R;
    cout << "Xin moi nhap cot: ";
    cin >> C;

   
    float **M = new float *[R];
    for (int i = 0; i < R; i++) {
        M[i] = new float[C];
    }

  
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << "Xin moi nhap phan tu hang " << i << " cot " << j << ": ";
            cin >> M[i][j];
        }
    }

    cout << "Ma tran vua nhap la:" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
