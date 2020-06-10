#include<iostream>


using namespace std;

class Matriz{

private:
    float** M;
    int nL, nC;

public:
    Matriz();
    Matriz(int nLinhas, int nColunas);
    ~Matriz();
    void set_nL(int nLinhas);
    void set_nC(int nColunas);
    int get_nL(void);
    int get_nC(void);
    void leMatriz();
    void leMatriz(int nLinhas, int nColunas);
    void imprimeMatriz();
    Matriz operator+(Matriz B);
    Matriz operator-(Matriz B);
    Matriz operator*(Matriz B);
    friend ostream& operator<<(ostream& os, Matriz &M);
};



