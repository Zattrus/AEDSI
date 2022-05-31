#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjunto.h"

int main()
{
    TConjunto a;
    CriaConjVazio(&a);
    int num, cond, op;

    do {
        printf("Menu do conjunto:\n1 = Insere no conjunto\n2 = Imprime conjunto\n3 = Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &num);
                LerConjunto(&a, num);
                break;
            case 2:
                ImprimeConjunto(&a);
                break;
            case 3:
                cond= -1;
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (cond != -1);
    return 0;
}
