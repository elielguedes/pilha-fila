#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 40

struct No
{
    float dados;
    struct No *prox;
};
struct PilhaDinamica
{
    struct No *top;
};
void CriarPilha(struct PilhaDinamica *p)
{
    p->top = NULL;
}

void pushD(struct PilhaDinamica *p, float Valor)
{
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    if (novo == NULL)
        printf("\n Erro de alocacao");
    else
    {
        novo->dados = Valor;
        novo->prox = p->top;
        p->top = novo;
    }
}

float popD(struct PilhaDinamica *p)
{
    float Valor;
    if (p->top == NULL)
        printf("\n Pilha Vazia!");
    else
    {
        struct No *pops = p->top;
        Valor = pops->dados;
        p->top = pops->prox;
        free(pops);
    }
    return Valor;
}

int PilhaVazia(struct PilhaDinamica *p)
{
    return (p->top == NULL);
}

void displaypilhad(struct PilhaDinamica *p)
{
    struct No *atual = p->top;
    printf("\n Topo -> ");
    while (atual != NULL)
    {
        printf("\n %.2f ", atual->dados);
        atual = atual->prox;
    }
    printf("\n<- base");
}

// Pilha estatica sequncial
struct PilhaStack
{
    float dados[MAXSIZE];
    int top;
};

typedef struct PilhaStack pilha;
pilha p;

void push(void);
int pop(void);
void display(void);

// Fila dinamica sequencial
struct Fila
{
    int capacidade;
    float *dados;
    int ini;
    int fim;
    int nitens;
};

void criar(struct Fila *f, int c)
{
    f->capacidade = c;
    f->dados = (float *)malloc(f->capacidade * sizeof(float));
    f->ini = 0;
    f->fim = -1;
    f->nitens = 0;
}

// elemento entra no fim da fila e para ser circular quando entra na mesma quantidade de itens ele renicia
void enqueue(struct Fila *f, int v)
{
    if (f->fim == f->nitens)
    {
        f->fim = -1;
    }
    else
    {
        f->dados[++f->fim] = v;
        f->nitens++;
    }
}

float dequeue(struct Fila *f)
{
    int remo = f->dados[f->ini++];
    if (f->ini == f->nitens)
        f->ini = 0;
    else
    {
        f->nitens--;
    }
    return remo;
}

int estacheia(struct Fila *f)
{
    return f->nitens == f->capacidade;
}

int estavazia(struct Fila *f)
{
    return f->nitens == 0;
}

void displayFila(struct Fila *f)
{
    int i, cont;
    for (cont = 0, i = f->ini; cont < f->nitens; cont++)
    {
        printf("\n %f elementos ", f->dados[i++]);
        if (i == f->capacidade)
            i = 0;
    }
}

int main()
{
    p.top = -1;
    int opcaofp;
    int capa, opcao, opcaop;
    float valor;
    struct Fila fila;

    while (true)
    {
        printf("\n 1 ----> fila dinamica encadeada");
        printf("\n 2 ----> Pilha estatica sequencial");
        printf("\n 3 ----> Pilha Dinamica encadeada ");
        printf("\n 4 ----> sair");

        printf("\n Digite opcao: ");
        scanf("%d", &opcaofp);
        if (opcaofp == 4)
        {
            break;
        }

        switch (opcaofp)
        {
        case 1:
            printf("\n Digite capacidade da fila: ");
            scanf("%d", &capa);
            criar(&fila, capa);
            while (true)
            {
                printf("\n -= Fila -=");
                printf("\n 1 ---> enqueue");
                printf("\n 2 ---> dequeue");
                printf("\n 3 ---> Mostrar");
                printf("\n 4 ---> Sair");

                printf("\n Digite opcao: ");
                scanf("%d", &opcao);
                switch (opcao)
                {
                case 1:
                    if (estacheia(&fila))
                        printf("\n Fila esta cheia !");
                    printf("\n informe elemento: ");
                    scanf("%f", &valor);
                    enqueue(&fila, valor);
                    break;
                case 2:
                    if (estavazia(&fila))
                    {
                        printf("\n Fila esta vazia !");
                    }
                    valor = dequeue(&fila);
                    printf("\n Valor removido %f ", valor);
                    break;
                case 3:
                    if (estavazia(&fila))
                        printf("\n Fila esta vazia !");
                    printf("\n Elementos da fila => ");
                    displayFila(&fila);
                    break;
                case 4:
                    return 0;
                default:
                    printf("\n Opcao errada");
                }
            }

        case 2:
            while (true)
            {
                printf("\n -= Pilha =-");
                printf("\n 1 ---> push");
                printf("\n 2 ---> pop");
                printf("\n 3 ---> display");
                printf("\n 4 ---> Sair");

                printf("\n Digite opcao acima:");
                scanf("%d", &opcaop);

                switch (opcaop)
                {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    return 0;
                }
            }
        case 3:
            float Valor;
            int opd;
            struct PilhaDinamica p;
            CriarPilha(&p);
            while (true)
            {
                printf("\n -=== Pilha Dinamica encadeada ===-");
                printf("\n 1 ---> push ");
                printf("\n 2 ---> pop ");
                printf("\n 3 ---> Display");
                printf("\n 4 ---> Sair");

                printf("\n Informe opcao desejada: ");
                scanf("%d", &opd);

                switch (opd)
                {
                case 1:
                    printf("\n Informe elemento: ");
                    scanf("%f", &Valor);
                    pushD(&p, Valor);
                    break;
                case 2:
                    Valor = popD(&p);
                    printf("\n %.2f elemento removido", Valor);
                    break;
                case 3:
                    printf("\n Elementos da pilha => ");
                    displaypilhad(&p);
                    break;
                case 4:
                    return 0;
                }
            }
        }
    }

    return 0;
}

void push()
{
    float num;
    if (p.top == (MAXSIZE - 1))
        printf("\n Pilha esta cheia !");
    else
    {
        printf("\n informe elemento desejado: ");
        scanf("%f", &num);
        p.dados[++p.top] = num;
    }
}

int pop()
{
    float num;
    if (p.top == -1)
        printf("\n Pilha esta vazia !");
    else
    {
        num = p.dados[p.top];
        printf("\n elemento %.2f removido", p.dados[p.top]);
        p.top--;
    }
    return num;
}

void display()
{
    if (p.top == -1)
        printf("\n Pilha esta vazia !");
    for (int i = p.top; i >= 0; i--)
    {
        printf("\n %.2f elementos da pilha", p.dados[i]);
    }
    printf("\n\n");
}