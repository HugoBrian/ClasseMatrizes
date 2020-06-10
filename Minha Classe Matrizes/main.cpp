#include<iostream>
#include"classe_matriz.h"

using namespace std;

int main(){


    int nL1,nL2,nC1,nC2;
    // Leitura das dimensoes das matrizes

    do
    {
        cout << "Numero de linhas 1: ";
        cin >> nL1;
    } while (nL1 <= 0);
    do
    {
        cout << "Numero de colunas 1: ";
        cin >> nC1;
    } while (nC1 <= 0);
    do
    {
        cout << "Numero de linhas 2: ";
        cin >> nL2;
    } while (nL2 <= 0);
    do
    {
        cout << "Numero de colunas 2: ";
        cin >> nC2;
    } while (nC2 <= 0);


    cout << endl;

    Matriz A(nL1,nC1),B(nL2,nC2);

    A.leMatriz();
    B.leMatriz();
    cout << endl;

    cout << A;
    cout << B;

    Matriz S = (A*B)+ B;

    cout << S;

    return 0;

}

