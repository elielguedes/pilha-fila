## 📦 Projeto: Pilha e Fila em C
📌 Descrição

Este projeto implementa duas estruturas fundamentais da Ciência da Computação:

Pilha (Stack) utilizando vetor estático
Fila (Queue) utilizando vetor dinâmico com comportamento circular simplificado

O sistema permite interação via menu, onde o usuário pode escolher entre operar com pilha ou fila.

🧠 Conceitos aplicados
📚 Pilha (Stack)

## Estrutura do tipo LIFO (Last In, First Out):

O último elemento inserido é o primeiro a sair
Operações principais:
push() → inserir no topo
pop() → remover do topo
display() → exibir elementos
📚 Fila (Queue)

## Estrutura do tipo FIFO (First In, First Out):

O primeiro elemento inserido é o primeiro a sair
Operações principais:
enqueue() → inserir no final
dequeue() → remover do início
displayFila() → exibir elementos
⚙️ Implementação
📌 Pilha (Estática)
Implementada com vetor de tamanho fixo (MAXSIZE = 40)
Controle feito por variável top
Verificação de:
pilha vazia
pilha cheia
📌 Fila (Estática dinâmica)
Implementada com alocação dinâmica (malloc)
Controle por:
ini (início)
fim (fim)
nitens (quantidade de elementos)
Simula comportamento circular básico
🧩 Funcionalidades
✔️ Pilha
Inserir elemento (push)
Remover elemento (pop)
Exibir elementos (display)
Controle de overflow e underflow
✔️ Fila
Inserir elemento (enqueue)
Remover elemento (dequeue)
Verificar se está vazia ou cheia
Exibir elementos em ordem FIFO
🖥️ Menu do sistema

## O programa possui interface em terminal:
```mermaid
  1 ----> Fila estatica sequencial
  2 ----> Fila dinamica encadedada
  3 ----> Pilha estatica sequecial
  4 ----> Pilha Dinamica encadeada
  5 ----> sair
  operacoes das filas =>
  1 ---> enqueue
  2 ---> dequeue
  3 ----> display
  4 ----> sair
operacoes das Pilhas =>
  1 ---> push
  2 ---> pop
  3 ---> display
  4 ---> sair
```
## Dentro de cada estrutura há menus específicos para operação.

⚠️ Observações técnicas
Uso de memória dinâmica na fila com malloc
Uso de vetor fixo na pilha
Estrutura simples para fins acadêmicos
Não possui liberação de memória (free) ao final
Implementação de fila circular simplificada
📌 Possíveis melhorias
Implementar fila circular completa (correta com módulo)
Adicionar free() na fila
Separar arquivos (pilha.c, fila.c, main.c)
Melhor tratamento de erros de entrada
Usar struct mais modular (encapsulamento)
🎯 Objetivo do projeto

Este projeto tem fins acadêmicos para:

Aprender estruturas de dados básicas
Entender comportamento de memória
Praticar lógica com ponteiros e arrays
Simular operações fundamentais de pilha e fila

👨‍💻 Linguagem utilizada
C (C99)
