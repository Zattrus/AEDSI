// Gabriel Amancio de Oliveira / 20.2.8184
// Wesley Souza da Silva / 20.2.8133
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 100

typedef struct
{
    int CPF;
    int idade;
    char sexo;
    char nome[MAXTAM];
    int grupo;
} TPaciente;

typedef struct
{
    TPaciente vPaciente[MAXTAM + 1];
    int Frente, Tras;
} TFila;

void FFVazia(TFila *pFila);
int Enfileira(TFila *pFila, TPaciente *pPaciente);
int Desinfileira(TFila *pFila, TPaciente *pPaciente);
void imprimeRealatorio(TFila *pFila);
int main()
{
    TFila pFila;
    FFVazia(&pFila);

    int contIdoso = 0;
    int contIndigena = 0;
    int contProfissional = 0;

    int cont = 0;
    int vacina = 0;
    int paciente = 0;

    printf("------------------Programa de Vacinacao Nacional------------------\n");
    printf("=============================================\n");
    printf("Qual a quantidade de vacina disponivel?: \n");
    scanf("%d", &vacina);
    printf("Qual a quantidade de pacinetes a serem cadastrados?: \n");
    scanf("%d", &paciente);
    printf("=============================================\n");

    // cadastro de pacientes
    for (int i = 0; i <= vacina; i++)
    {
        if (paciente >= 0)
        {
            TPaciente pPaciente;
            fflush(stdin);
            printf("======================= Paciente: %i =======================\n", i + 1);
            printf("Qual o nome do paciente?: ");
            getchar();
            fgets(pPaciente.nome, MAXTAM, stdin);
            printf("Qual o CPF do paciente?: ");
            scanf("%d", &pPaciente.CPF);
            fflush(stdin);
            printf("Qual a idade do paciente?: ");
            scanf("%i", &pPaciente.idade);
            fflush(stdin);
            printf("Qual o sexo do paciente?: ");
            scanf("%s", &pPaciente.sexo);
            fflush(stdin);
            printf("Qual o grupo a pessoa pertence: \n Gp 1: Idoso \n Gp 2: Indigena \n Gp 3: Profissioanl da saude \n");
            scanf("%i", &pPaciente.grupo);
            fflush(stdin);

            while (Enfileira(&pFila, &pPaciente))
            {
                if (pPaciente.grupo == 1)
                {
                    contIdoso++;
                }
                else if (pPaciente.grupo == 2)
                {
                    contIndigena++;
                }
                else if (pPaciente.grupo == 3)
                {
                    contProfissional++;
                }
                else
                {
                    printf("Grupo invalido");
                }
                printf("=============================================\n");
                printf("CADASTRADO COM SUCESSO!\n");
                printf("=============================================\n");
                break;
            }
            vacina--;
            paciente--;
            cont++;
        }
        else
        {
            printf("Nao ha mais Pacientes!\n");
            // break;
        }

        if (vacina <= 0)
        { // Faz com que, caso a quantidade de vacinas seja 0, printa a msg de que acabou as vacinas e os pacientes restantes nao serao cadastrados
            printf("O estoque de vacinas acabou");
        }
    }

    // Estoque de vacinas restantes
    printf("=============================================\n");
    printf("Estoque de vacinas restantes: %i\n", vacina);

    // Total de pessoas vacinadas
    printf("=============================================\n");
    printf("Total de pacientes vacinados: %i\n", cont);

    // Total em cada grupo
    printf("=============================================\n");
    printf("Grupo 1 - Idoso: %i\n", contIdoso);
    printf("Grupo 2 - Indigena: %i\n", contIndigena);
    printf("Grupo 3 - Profissional da saude: %i\n", contProfissional);

    // Imprime relatório det todos os pacientes cadastrados
    printf("=============================================\n");
    printf("Relatorio de todos os pacientes cadastrados:\n");
    imprimeRealatorio(&pFila);
    return 0;
}

void FFVazia(TFila *pFila)
{
    pFila->Frente = 0;
    pFila->Tras = pFila->Frente;
}

int FVazia(TFila *pFila)
{
    return (pFila->Frente == pFila->Tras);
}

int Enfileira(TFila *pFila, TPaciente *pPaciente)
{
    if (((pFila->Tras + 1) % (MAXTAM + 1)) == pFila->Frente)
    {
        return 0;
    }
    pFila->vPaciente[pFila->Tras] = *pPaciente;
    pFila->Tras = (pFila->Tras + 1) % (MAXTAM + 1);
    return 1;
}

int Desinfileira(TFila *pFila, TPaciente *pPaciente)
{
    if (FVazia(pFila))
        return 0;
    *pPaciente = pFila->vPaciente[pFila->Frente];
    pFila->Frente = (pFila->Frente + 1) % (MAXTAM + 1);
    return 1;
}

void imprimeRealatorio(TFila *pFila)
{
    TPaciente contIdoso;
    TPaciente contIndigena;
    TPaciente contProfissional;
    int a = 0;
    for (int i = pFila->Frente; i < pFila->Tras; i++)
    {
        printf("\nPaciente %i ", a++);
        printf("\nCPF: %d", pFila->vPaciente[i].CPF);
        printf("\nIdade: %i", pFila->vPaciente[i].idade);
        printf("\nSexo: %c", pFila->vPaciente[i].sexo);
        printf("\nGrupo: %d\n", pFila->vPaciente[i].grupo);
    }
}