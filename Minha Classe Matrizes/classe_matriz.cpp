#include<iostream>
#include "classe_matriz.h"

using namespace std;

void Matriz::set_nL(int nLinhas){
    nL = nLinhas;
}
void Matriz::set_nC(int nColunas){
    nC = nColunas;
}
int Matriz::get_nL(void){
    return nL;
}
int Matriz::get_nC(void){
    return nC;
}

Matriz::Matriz(){
    nL = 1;
    nC = 1;

    this->M = new float* [0];
    for(int i=0; i<nL; i++){
        M[i] = new float [0];
    }
}

Matriz::Matriz(int nLinhas, int nColunas){
    nL = nLinhas;
    nC = nColunas;

    this->M = new float* [nLinhas];
    for(int i=0; i<nL; i++){
        M[i] = new float [nColunas];
    }
}

Matriz::~Matriz(){
    if(nL == 1 && nC == 1){
        delete[] M;
        return;
    }
    for(int i=0; i<nC; i++){
        delete[] M[i];
    }
    delete[] M;
}

void Matriz::leMatriz(){

    if(nL == 1 && nC == 1){
        cin >> **M;
        return;
    }

    for(int i=0; i<nL; i++){
        for(int j=0; j<nC; j++){
            cin >> M[i][j];
        }
    }
}

void Matriz::imprimeMatriz(){

    if(nL == 1 && nC == 1){
        cout << M[0][0];
        return;
    }

    for(int i=0; i<nL; i++){
        if(i != 0)
            cout << endl;
        for(int j=0; j<nC; j++){
            cout << M[i][j] << " ";
            if(i == nL-1 && j == nC-1){
                cout << endl;
            }
        }
    }
    cout << endl;
}

Matriz  Matriz::operator+(Matriz B){

    int maiorL, maiorC;

    if(this->nL > B.nL){
        maiorL = this->nL;
    }else{
        maiorL = B.nL;
    }

    if(this->nC > B.nC){
        maiorC = this->nC;
    }else{
        maiorC = B.nC;
    }
    Matriz S(maiorL,maiorC);
    for(int i=0; i<maiorL; i++){
        for(int j=0; j<maiorC; j++){

            if(i >= this->nL && j < B.nC){
                S.M[i][j] = B.M[i][j];
            }else if(j >= B.nC && i < this->nL){
                S.M[i][j] = this->M[i][j];
            }else if(i >= this->nL && j >= B.nC){
                S.M[i][j] = 0;
            }else{
                S.M[i][j] = this->M[i][j] + B.M[i][j];
            }
        }
    }
    return S;
}


Matriz  Matriz::operator-(Matriz B){

    int maiorL, maiorC;

    if(this->nL > B.nL){
        maiorL = this->nL;
    }else{
        maiorL = B.nL;
    }

    if(this->nC > B.nC){
        maiorC = this->nC;
    }else{
        maiorC = B.nC;
    }
    Matriz S(maiorL,maiorC);

    for(int i=0; i<maiorL; i++){
        for(int j=0; j<maiorC; j++){

            if(i >= this->nL && j < B.nC){
                S.M[i][j] = B.M[i][j];
            }else if(j >= B.nC && i < this->nL){
                S.M[i][j] = this->M[i][j];
            }else if(i >= this->nL && j >= B.nC){
                S.M[i][j] = 0;
            }else{
                S.M[i][j] = this->M[i][j] - B.M[i][j];
            }
        }
    }
    return S;
}


Matriz  Matriz::operator*(Matriz B){

    if(nC != B.get_nL()){
        cout << "dimensoes invalidas para multiplicao.";
        Matriz erro(0,0);
        return erro;
    }

    Matriz P(nL,B.nC);
    float aux=0;
    for(int i=0; i<nL; i++){
        for(int j=0; j<B.nC; j++){
            P.M[i][j] = 0;
            for(int k=0; k<B.nL; k++){
                aux += M[i][k] * B.M[k][j];
            }
            P.M[i][j] = aux;
            aux = 0;
        }
    }

    return P;
}

ostream& operator<<(ostream& os, Matriz &M){
   if(M.nL == 1 && M.nC == 1){
        os << M.M[0][0];
        return os;
    }

    for(int i=0; i<M.nL; i++){
        if(i != 0)
            os << endl;
        for(int j=0; j<M.nC; j++){
            os << M.M[i][j] << " ";
            if(i == M.nL-1 && j == M.nC-1){
                os << endl;
            }
        }
    }
    os << endl;
  return os;
}
