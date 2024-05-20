#include <stdio.h>
#include <stdio.h>
#include "contatos.h"

int main() {
    int opcao;
    int pos = 0;
    Agenda contatos[TOTAL];

    do {
        printf("\nMenu principal\n");
        printf("1 - Criar contato\n");
        printf("2 - Deletar contato\n");
        printf("3 - Listar contatos\n");
        printf("4 - Salvar agenda\n");
        printf("5 - Carregar agenda\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("Opcao escolhida: %d\n", opcao);

        switch (opcao) {
            case 1:
                criar(contatos, &pos);
                break;
            case 2: {
                char telefone_a_remover[20];
                printf("Digite o número de telefone do contato que deseja remover: ");
                scanf("%19s", telefone_a_remover);
                deletar(contatos, telefone_a_remover, &pos);
                break;
}
            case 3:
                listar(contatos, &pos);
                break;
            case 4:
                salvar(contatos, &pos, TOTAL);
                break;
            case 5:
                carregar(contatos, &pos, TOTAL);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}