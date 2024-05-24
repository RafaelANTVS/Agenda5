#include <stdio.h>
#include <string.h>
#include "contatos.h"

ERROS criar(Agenda contatos[], int *pos, int type) {
    char telefone_digitar[20];
    int i;

    if (*pos >= TOTAL) { 
        printf("Agenda lotada!");
        return AGENDA_LOTADA;
    }

    printf("Entre com o telefone: ");
    scanf("%19s", telefone_digitar);

    for (i = 0; i < *pos; i++) {
        if (strcmp(contatos[i].telefone, telefone_digitar) == 0) {
            printf("Telefone já existente!\n");
            return TELEFONE_EXISTENTE;
        }
    }

    strcpy(contatos[*pos].telefone, telefone_digitar);

    printf("Entre com o nome do contato: ");
    scanf("%99s", contatos[*pos].nome);
    clearBuffer();

    char email[100];
    int emailValido = 0;
    do {
        printf("Entre com o email: ");
        scanf("%99s", email);
        clearBuffer();

        const char *arroba = strchr(email, '@');
        const char *ponto = arroba ? strchr(arroba, '.') : NULL;

        if (arroba && ponto && arroba != email && ponto > arroba + 1 && *(ponto + 1) != '\0') {
            emailValido = 1;
        } else {
            printf("Email inválido! Tente novamente.\n");
        }
    } while (!emailValido);

    strcpy(contatos[*pos].email, email);

    (*pos)++;

    return OK;
}

ERROS listar(Agenda contatos[], int *pos, int type) {
    if (*pos == 0)
        printf("Sem contatos para exibir!");

    for (int i = 0; i < *pos; i++) {
        printAgenda(contatos[i], i + 1, type);
    }

    return OK;
}

ERROS deletar(Agenda contatos[], char *telefone, int *pos, int type) {
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

void printAgenda(Agenda contatos, int pos, int type) {
    printf("\nPosicao: %d\t", pos);
    printf("Nome: %s\tEmail: %s\t", contatos.nome, contatos.email);
    printf("Telefone: %s\n", contatos.telefone);
}

ERROS mudar(Agenda contatos[], int *pos, int tamanho, int type){
    int i, j,opcao, encontrado = 0;
    char nome[100], telefone[20], email[100], NovoNome[100],NovoTelefone[20],NovoEmail[100];
    printf("Qual tipo de mudança?(1-Nome, 2-Telefone, 3-Email) \n");
    scanf("%d", &opcao);

    if(opcao == 1){
        printf("Digite o nome do contato a ser mudado\n");
        scanf("%s", nome);
        for (i = 0; i < *pos; i++){
            if (strcmp(contatos[i].nome,nome) ==0){
                printf("Digite o novo nome: \n");
                scanf("%s", NovoNome);
                strcpy(contatos[j].nome, NovoNome);
                printf("O contato foi mudado com sucesso!\n");
                printf("Novo nome:%s\n", contatos[j].nome);
        } else {
            printf("Nome não encontrado!\n");
                }
            }
        } else if ( opcao == 2) {
            printf("Digite o telefone do contato a ser mudado\n");
            scanf("%s", telefone);
        for (i = 0; i < *pos; i++){
            if (strcmp(contatos[i].telefone,telefone) ==0){
                printf("Digite o novo telefone: \n");
                scanf("%s", NovoTelefone);
                strcpy(contatos[j].telefone, NovoTelefone);
                printf("O contato foi mudado com sucesso!\n");
                printf("Novo telofone:%s\n", contatos[j].telefone);
        } else {
            printf("Telefone não encontrado!\n");
                }
            }
        } else if (opcao == 3){
            printf("Digite o email do contato a ser mudado\n");
            scanf("%s", email);
        for (i = 0; i < *pos; i++){
            if (strcmp(contatos[i].email,email) ==0){
                printf("Digite o novo email: \n");
                scanf("%s", NovoEmail);
                strcpy(contatos[j].email, NovoEmail);
                printf("O contato foi mudado com sucesso!\n");
                printf("Novo email:%s\n", contatos[j].email);
        } else {
            printf("Email Não encontrado!\n");
                }
            }
        }
}


void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
