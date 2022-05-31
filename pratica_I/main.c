#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjunto.h"

int main()
{
    TConjunto conjA, conjB, conjC, conjD;

    CriaConjVazio(&conjA);
    CriaConjVazio(&conjB);
    CriaConjVazio(&conjC);
    CriaConjVazio(&conjD);

    printf("\nDados do conjunto A: \n");
    LerConjunto(&conjA);
    printf("\nDados do conjunto B: \n");
    LerConjunto(&conjB);

    printf("\nConjunto A: ");
    Imprime(&conjA);

    printf("\nConjunto B: ");
    Imprime(&conjB);

    printf("\n\nVerificacao de Igualdade (A e B): ");
    Iguais(&conjA, &conjB);

    Uniao(&conjA, &conjB, &conjD);
    printf("\nUniao: ");
    Imprime(&conjD);

    Intersecao(&conjA, &conjB, &conjC);
    printf("\nInterseccao: ");
    Imprime(&conjC);

    return 0;
}
