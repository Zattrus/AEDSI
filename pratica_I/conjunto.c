#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

void CriaConjVazio(TConjunto *conjA)
{
    int i;
    conjA->num = 0;
    for (i = 0; i < MAXTAM; i++)
    {
        conjA->vet[i] = 0;
    }
}

void LerConjunto(TConjunto *conj)
{
    int n, i = 0, valor, verificador = 0;
    printf("Insere os elementos ");
    scanf("%d", &n);
    do
    {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &valor);
        for (int j = 0; j < conj->num; j++)
        {
            if (conj->vet[j] == valor)
            {
                verificador = -1;
            }
        }
        if (verificador == -1)
        {
            printf("\nEste elemento ja pertence ao conjunto! \n");
        }
        else
        {
            conj->vet[i] = valor;
            conj->num++;
            i++;
        }
        verificador = 0;
    } while (i < n);
}

void Uniao(TConjunto *conjA, TConjunto *conjB, TConjunto *conjC)
{
    int v = 0, verificador = 0;
    for (int i = 0; i < conjA->num; i++)
    {
        conjC->vet[i] = conjA->vet[i];
        conjC->num++;
        v++;
    }

    for (int j = 0; j < conjB->num; j++)
    {
        for (int k = 0; k < conjA->num; k++)
        {
            if (conjB->vet[j] == conjA->vet[k])
            {
                verificador = -1;
            }
        }
        if (verificador != -1)
        {
            conjC->vet[v] = conjB->vet[j];
            conjC->num++;
            v++;
        }
        verificador = 0;
    }
}

TConjunto Intersecao(TConjunto *conjA, TConjunto *conjB, TConjunto *conjC)
{
    int k = 0;
    for (int i = 0; i < conjA->num; i++)
    {
        for (int j = 0; j < conjB->num; j++)
        {
            if (conjA->vet[i] == conjB->vet[j])
            {
                conjC->vet[k] = conjA->vet[i];
                conjC->num++;
                k++;
            }
        }
    }
}

void Iguais(TConjunto *conjA, TConjunto *conjB)
{
    int i, j;
    for (i = 0; i < conjA->num; i++)
    {
        for (j = 0; j < conjB->num; j++)
        {
            if (conjA->vet[i] == conjB->vet[j])
            {
                break;
            }
            else
            {
                printf("Os conjuntos nao sao iguais\n");
                break;
            }
        }
    }
    printf("Os conjuntos sao iguais\n");
}

void Imprime(TConjunto *conj)
{
    int i;
    printf("\nConjunto");
    for (i = 0; i < conj->num; i++)
    {
        printf("%d ", conj->vet[i]);
    }
}