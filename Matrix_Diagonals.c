/*
    Lucas Arneiro Vieira
    14/11/2018 - Matriz em C

*/

/*
int matriz [3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Primeiro [] são as linhas e segundo [] são as colunas.
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(void)
{
//=================================== Varredura de Matriz e Soma de Diagonais ========================================
    int matriz[3][3] = {{11, 2, 4},
                        {4, 5, 6},
                        {10, 8, -12}}; //---> Valores de matriz aleatórios com diagonais principal e secundária sendo 1.*/
    int i, j;
    int soma_principal = 0;
    int soma_secundaria = 0;
    int x = 0;

    printf("\n\t\t\tMatriz: \n\n");
    for(i = 0; i < 3; ++i){  // Padrão para varrer uma matriz com ciclo for.
        for(j = 0; j < 3; ++j){
            printf("%3d ", matriz[i][j]); // Exibir matriz com valores espaçados
            if(i==j){                    // Se posições de linha e coluna da matriz são iguais =  diagonal principal;
                soma_principal += matriz[i][j]; // Soma da diagonal principal = soma_principal + matriz[i][j].
            }
            if(i + j == 2){
                soma_secundaria += matriz[i][j]; // Diagonal secundária: [0][4] - [1][3] - [2][2]
                                                //                       [3][1] - [4][0]. i == numero_colunas - 1 -j ou j == nlinhas -1 - i. i + j == ncoluna ou linhas -1.
            }
        }
        printf("\n");
    }
    x = abs(soma_principal - soma_secundaria);
    printf("\n\nValor da soma da diagonal principal: %d\n", soma_principal);
    printf("\n\nValor da soma da diagonal secundaria: %d\n", soma_secundaria);
    printf("\n\nValor da soma da diferença entre as diagonais eh: %d\n", x);


    return 0;
}
