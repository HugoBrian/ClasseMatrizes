# ClasseMatrizes

* Desenvolvimento de um *classe* para tratamento de matrizes com sobrecarga de operadores em C++. Projeto proposto na diciplina de Paradigmas de Programação da Universidade Federal do Rio Grande do Norte(UFRN).
* A operação de soma possui característica diferente da formalidade matemática como é descrito abaixo.
   
* A partir de duas matrizes de floats passadas como parâmetro, aloca e retorna uma matriz
   igual à soma das matrizes originais.
   O número de linhas e colunas da matriz soma será o maior número de linhas e colunas nas duas matrizes
   originais, respectivamente. Por exemplo, se uma das matrizes originais tem dimensão 3x4 e a outra, 4x2,
   então a matriz soma terá dimensões 4 (máx entre 3 e 4) x 4 (máx entre 4 e 2).
   Caso a linha e coluna em questão existam nas duas matrizes, o elemento correspondente na matriz soma
   será a soma dos dois elementos nas matrizes originais. Caso só existam em uma das matrizes, será igual
   ao elemento existente em uma das matrizes originais. Caso não existam em nenhuma das matrizes originais,
   o elemento correspondente na matriz soma será 0 (zero).
