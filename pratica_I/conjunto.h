#define MAXTAM 100

typedef struct
{
    int vet[MAXTAM];
    int num;

} TConjunto;

void CriaConjVazio(TConjunto *conj);
void LerConjunto(TConjunto *conj);
void Uniao(TConjunto *conjA, TConjunto *conjB, TConjunto *conjC);
TConjunto Intersecao(TConjunto *conjA, TConjunto *conjB, TConjunto *conjC);
void Iguais(TConjunto *conjA, TConjunto *conjB);
void Imprime(TConjunto *conj);
