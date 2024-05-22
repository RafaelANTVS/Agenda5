#include <stdio.h>
#include <string.h>
#include "contatos.h"

ERROS criar(Agenda contatos[], int *pos) {
    char telefone_digitar[20]; // Adicionei a declaração do array de char para armazenar o telefone digitado
    int i;

    if (*pos >= TOTAL) { // Corrigido: Adicionei chaves para delimitar o bloco de código
        printf("Agenda lotada!");
        return AGENDA_LOTADA; // Corrigido: Retornei um erro quando a agenda estiver lotada
    }

    printf("Entre com o telefone: ");
    scanf("%19s", telefone_digitar); // Corrigido: Armazenei o telefone digitado na variável 'telefone_digitar'

    // Verifica se o telefone já existe na agenda
    for (i = 0; i < *pos; i++) {
        if (strcmp(contatos[i].telefone, telefone_digitar) == 0) { // Corrigido: Usei strcmp para comparar strings
            printf("Telefone já existente!\n");
            return TELEFONE_EXISTENTE; // Corrigido: Retornei um erro quando o telefone já existir
        }
    }

    // Se o telefone não existir na agenda, continue com a inserção
    strcpy(contatos[*pos].telefone, telefone_digitar); // Corrigido: Copiei o telefone digitado para o array de contatos

    printf("Entre com o nome do contato: ");
    scanf("%99s", contatos[*pos].nome);
    clearBuffer();

    printf("Entre com o email: ");
    scanf("%99s", contatos[*pos].email);
    clearBuffer();

    (*pos)++;

    return OK;
}

ERROS listar(Agenda contatos[], int *pos) {
    if (*pos == 0)
        printf("Sem contatos para exibir!");

    for (int i = 0; i < *pos; i++) {
        printAgenda(contatos[i], i + 1);
    }

    return OK;
}

ERROS deletar(Agenda contatos[], char *telefone, int *pos) {
    int i;
    int encontrado = 0;

    if (*pos <= 0) {
        return SEM_CONTATOS;
    }

    for (i = 0; i < *pos; i++) {
        if (strcmp(contatos[i].telefone, telefone) == 0) {
            encontrado = 1;

            for (int j = i; j < *pos - 1; j++) {
                strcpy(contatos[j].nome, contatos[j + 1].nome);
                strcpy(contatos[j].email, contatos[j + 1].email);
                strcpy(contatos[j].telefone, contatos[j + 1].telefone);
            }
            (*pos)--;
            printf("Contato removido com sucesso!\n");
            break;
        }
    }
    for(int i=0; i<*pos; i++){
        printf("Pos: %c\t", i+1);
        printf("Nome: %s\t", contatos[i].nome);
        printf("email: %s\t", contatos[i].email);
        printf("telefone: %s\n", contatos[i].telefone);
    if (!encontrado) {
        printf("Contato com o número de telefone %s não encontrado.\n", telefone);
        return NAO_ENCONTRADO;
    }

    return OK;
    }
}
ERROS salvar(Agenda contatos[], int *pos, int tamanho) {
    FILE *f = fopen("agenda.bin", "wb");
    if (f == NULL)
        return ABRIR;
    for (int i = 0; i < *pos; i++) {
        if (fwrite(&contatos[i], sizeof(Agenda), 1, f) != 1) {
            fclose(f);
            return ESCREVER;
        }
    }
    if (fwrite(pos, sizeof(int), 1, f) != 1) {
        fclose(f);

    int qtd = fwrite(contatos, sizeof(Agenda), *pos, f);
    if (qtd != *pos)
        return ESCREVER;

    if (fwrite(pos, sizeof(int), 1, f) != 1)
        return ESCREVER;
    }
    if (fclose(f) != 0)
        return FECHAR;
        printf("Arquivo salvo com sucesso!");
    return OK;
}

ERROS carregar(Agenda contatos[], int *pos, int tamanho) {
    FILE *f = fopen("agenda.bin", "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo agenda.bin\n");
        return ABRIR;
    }
    int i;
    for (i = 0; i < tamanho && fread(&contatos[i], sizeof(Agenda), 1, f) == 1; i++);
    *pos = i;
    if (fclose(f) != 0) {
        printf("Erro ao fechar o arquivo agenda.bin\n");
        return FECHAR;
    }
    printf("Arquivo aberto com sucesso!");
    return OK;
}
void printAgenda(Agenda contatos, int pos) {
    printf("\nPosicao: %d\t", pos);
    printf("Nome: %s\tEmail: %s\t", contatos.nome, contatos.email);
    printf("Telefone: %s\n", contatos.telefone);
}


void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

}
