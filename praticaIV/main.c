//Arthur Wolff Soares 20.2.8063
//Gabriel Amancio de Oliveira 20.2.8184

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TamMax 100

typedef struct Cadastro
{
    char nome[TamMax];
    int idade;
}TCadastro;

typedef struct Fila
{
    TCadastro vCadastro[TamMax+1];
    int Frente, Tras, n;
}TFila;

void FFilaVazia     (TFila* pFila);
int  FilaVazia      (TFila* pFila);
int  Enfilheira     (TFila* pfila, TCadastro* pPaciente);
int  Desenfilheira  (TFila* pfila, TCadastro* pPaciente);

void InicializaP    (TFila* pfila);
int  Pesquisa_seq2  (TFila* pfila, char nome[TamMax]);
void Insere         (TFila* pfila, TCadastro pPacientes);

int main()
{

    int n_pacientes = 0;
    int i_nome_pesquisa = 0;
    char p_nome[TamMax];

    TCadastro pacientes;
    TFila     vacinacao;

    FFilaVazia(&vacinacao);
    FilaVazia(&vacinacao);
    InicializaP(&vacinacao);

    printf  ("Insira o numero de pacientes que se deseja vacinar: ");
    scanf("%d", &n_pacientes);


    for (int i = 0; i < n_pacientes; i++)
                {

                    printf("\nCADASTRO DO PACIENTE %d -------------------------------\n", i+1);

                    fflush(stdin);
                    printf("Nome do paciente: ");
                    gets(pacientes.nome);

                    printf  ("Idade: ");
                    scanf("%d", &pacientes.idade);

                    Enfilheira(&vacinacao, &pacientes);
                   
                    printf  ("\n\n------------------------------- CADASTRO REALIZADO -------------------------------\n\n");
                }
    printf  ("\n");

    fflush(stdin);
    printf("Digite o nome que deseja pesquisar: ");
    gets(p_nome);

    i_nome_pesquisa = Pesquisa_seq2(&vacinacao, p_nome);

    printf  ("Resultado da pesquisa---------------------\nNome: %s \nIdade: %i", vacinacao.vCadastro[i_nome_pesquisa].nome, vacinacao.vCadastro[i_nome_pesquisa].idade );
    
    return 0;
}


void FFilaVazia(TFila* pfila){
    pfila->Frente = 0;
    pfila->Tras = pfila->Frente;
}

int FilaVazia   (TFila* pfila){
    return  (pfila->Frente == pfila->Tras);
}

int Enfilheira (TFila* pfila, TCadastro* pPaciente){

        if (((pfila->Tras+1)%(TamMax+1)) == pfila->Frente)
        {
           return 0;
        }
        else
        {
            pfila->vCadastro[pfila->Tras] = *pPaciente;
            pfila->Tras = (pfila->Tras+1) % (TamMax+1);
            Insere(pfila,*pPaciente);
            return 1;
        }
}

int Desenfilheira   (TFila* pfila, TCadastro* pPaciente){

    if (FilaVazia(pfila))
    {
        return 0;
    }
    else
    {
        *pPaciente = pfila->vCadastro[pfila->Frente];
        pfila->Frente = (pfila->Frente+1) % (TamMax+1);
        return  1;
    }
}

void InicializaP (TFila *pfila){
    pfila->n = 0;
}

int Pesquisa_seq2(TFila *pfila, char nome[TamMax]){
    int i;
    
    strcpy(pfila ->vCadastro[0].nome, nome);
     

    i = pfila->n;

    while (strcmp(pfila->vCadastro[i].nome, nome) != 0)
    {
        i--;
    }
    return i;
}

void Insere (TFila *pfila, TCadastro pPacientes){

    if (pfila->n == TamMax)
    {
        printf("Cheio");
    }
    else
    {
        pfila->n++;
        pfila->vCadastro[pfila->n] = pPacientes;
    }

}



