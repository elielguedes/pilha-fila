#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 40

/*
desenvolver um algoritimo que possui uma fila circular e uma pilha aonde vai ter um menu
para o usuario escolher se ele que fila ou quer pilha ou quer sair
o usuario escolher pilha terá as operações de push , pop , mostrar sair
já se user escolher fila terá operações de enqueue , dequeue , de enqueue(dequeue()) e sair

*/
struct PilhaStack
{
    int dados[MAXSIZE];
    int top;
};

typedef struct PilhaStack pilha;
pilha p;

void push(void);
int pop(void);
void display(void);

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
/*
já aqui o primeiro que entra na fila e o ultimo a sair e returna o elemento retirado por isso não
é um (void) então inicio se incrementa para ser circular preciso de reinciar quando o inicio chegar
na quantidade de elementos ele reicioa e preocura espaços vazios

*/
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
        printf("\n 1 ----> fila ");
        printf("\n 2 ----> Pilha");
        printf("\n 3 ----> sair");
        printf("\n Digite opcao: ");
        scanf("%d", &opcaofp);
        if (opcaofp == 3)
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
                printf("\n -= Pila =-");
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
        }
    }

    return 0;
}

void push()
{
    int num;
    if (p.top == (MAXSIZE - 1))
        printf("\n Pilha esta cheia !");
    else
    {
        printf("\n informe elemento desejado: ");
        scanf("%d", &num);
        p.dados[++p.top] = num;
    }
}

int pop()
{
    int num;
    if (p.top == -1)
        printf("\n Pilha esta vazia !");
    else
    {
        num = p.dados[p.top];
        printf("\n elemento %d removido", p.dados[p.top]);
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
        printf("\n %d elementos da pilha", p.dados[i]);
    }
    printf("\n\n");
}