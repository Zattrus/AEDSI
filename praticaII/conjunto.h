typedef struct Nodo {
    struct Nodo *prox;
}TNodo;

typedef struct {
    TNodo *prim;
    TNodo *ult;
    int tam;
} TConjunto;


// Prototipos
void CriaConjVazio(TConjunto *conj);
void LerConjunto(TConjunto *conj, int info);
void Uniao(TConjunto *conj1, TConjunto *conj2);
void Intersecao(TConjunto *conj1, TConjunto *conj2, TConjunto *conj3);
void Iguais(TConjunto *conj1, TConjunto *conj2);
void ImprimeConjunto(TConjunto *conj);