// TAD Deque de caracteres (testes completos)
// Programa de teste seguro inspirado no estilo FPRIO

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// imprime o estado do deque
void deque_print_safe(struct deque *d) {
    if (!d) return;
    printf("Deque: ");
    dequePrint(d);
    int sz = dequeSize(d);
    printf(" (size = %d)\n", sz);
}

// imprime mensagem de erro e encerra execução
void erro(char *msg) {
    fprintf(stderr, "ERRO: %s\n", msg);
    exit(1);
}

// cria um char e verifica sucesso
char make_char(char value) {
    return value; // trivial, mas mantém padrão FPRIO
}

int main() {
    struct deque *d;
    char c;
    int ret;

    printf("Cria deque vazio\n");
    d = makeDeque();
    if (!d) erro("Não foi possível criar deque");
    deque_print_safe(d);
    printf("\n");

    printf("Testa popFront e popBack em deque vazio\n");
    ret = popFront(d, &c);
    printf("popFront retornou: %d (esperado 2)\n", ret);
    ret = popBack(d, &c);
    printf("popBack retornou: %d (esperado 2)\n", ret);
    deque_print_safe(d);
    printf("\n");

    printf("Insere elementos no deque (teste pushFront e pushBack)\n");
    pushFront(d, make_char('A'));
    pushBack(d, make_char('B'));
    pushFront(d, make_char('C'));
    pushBack(d, make_char('D'));
    deque_print_safe(d);
    printf("\n");

    printf("Remove elementos do deque (teste popFront/popBack alternados)\n");
    popFront(d, &c);
    printf("popFront removeu: %c\n", c);
    popBack(d, &c);
    printf("popBack removeu: %c\n", c);
    popFront(d, &c);
    printf("popFront removeu: %c\n", c);
    deque_print_safe(d);
    printf("\n");

    printf("Adiciona mais elementos para teste de ordem\n");
    pushBack(d, make_char('X'));
    pushBack(d, make_char('Y'));
    pushBack(d, make_char('Z'));
    pushFront(d, make_char('M'));
    pushFront(d, make_char('N'));
    deque_print_safe(d);
    printf("\n");

    printf("Remove todos os elementos e verifica ordem\n");
    char prev = '\0';
    while ((ret = popFront(d, &c)) == 0) {
        printf("Removido: %c\n", c);
        if (prev != '\0' && prev == c) {
            erro("Erro: caractere repetido inesperado");
        }
        prev = c;
        deque_print_safe(d);
    }
    printf("popFront retornou: %d (esperado 2 para empty)\n", ret);
    printf("\n");

    printf("Testa operações inválidas (ponteiro NULL)\n");
    ret = popFront(NULL, &c);
    printf("popFront(NULL) retornou: %d (esperado 1)\n", ret);
    ret = popBack(NULL, &c);
    printf("popBack(NULL) retornou: %d (esperado 1)\n", ret);
    ret = dequeSize(NULL);
    printf("dequeSize(NULL) retornou: %d (esperado -1)\n", ret);
    printf("\n");

    printf("Testa pushFront/pushBack com deque NULL (deve retornar erro 1)\n");
    ret = pushFront(NULL, 'X');
    printf("pushFront(NULL) retornou: %d (esperado 1)\n", ret);
    ret = pushBack(NULL, 'Y');
    printf("pushBack(NULL) retornou: %d (esperado 1)\n", ret);
    printf("\n");

    printf("Destroi deque\n");
    destroyDeque(d);
    printf("Deque destruído com sucesso\n");

    return 0;
}