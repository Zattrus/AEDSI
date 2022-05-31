#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

void CriaConjVazio(TConjunto *conj){
    conj->prim = NULL;
    conj->ult = NULL;
    conj->tam = 0;
}

void LerConjunto(TConjunto *conj, int info) {
    int verif = 0;
    TNodo *pAux = conj->prim;
    while(pAux != NULL)
    {
        if(pAux->info == info){
            verif = -1;
            printf("Elemento ja existe no conjunto!\n");
        }
        pAux = pAux->prox;
    };
    
    if(verif == 0){
        if(conj->ult == NULL){
            conj->ult = (TNodo*) malloc(sizeof(TNodo));
            conj->prim = conj->ult;
        }else {
            conj->ult->prox = (TNodo*) malloc(sizeof(TNodo));
            conj->ult = conj->ult->prox;
        }    
        conj->ult->info = info;
        conj->ult->prox = NULL;
        conj->tam++;
    }
}

void Uniao(TConjunto *conj1, TConjunto *conj2) {
    
}


void Intersecao(TConjunto *conjA, TConjunto *conjB, TConjunto *conjC){

}


void Iguais(TConjunto *conj1, TConjunto *conj2){
    int verif = 0;
    if(conj1 -> tam != conj2 -> tam){
        verif = -1;
    }
    // Falta verificar se são diferentes com tamanhos iguais
    if (verif == 0){
        printf("Conjuntos sao iguais\n");
    }else{
        printf("Conjuntos sao diferentes\n");
    }
}

void ImprimeConjunto(TConjunto *conj) {
    TNodo *pAux;
    pAux = conj->prim;
    printf("\n[");
    do{
        printf(" %d ", pAux->info);
        pAux = pAux->prox;
    }while(pAux != NULL);
    printf("]\n");
}

