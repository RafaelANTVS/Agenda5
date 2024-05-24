
#include <stdio.h>
#include "contatos.h"

int main() {
    int opcao;
    int opcao2;
    int pos = 0;
    int pos_trabalho = 0;
    Agenda contatos[TOTAL];
    Agenda contatos_trabalho[TOTAL];

    do {
        printf("\nMenu principal\n");
        printf("1 - Criar contato\n");
        printf("2 - Deletar contato\n");
        printf("3 - Listar contatos\n");
        printf("4 - Salvar agenda\n");
        printf("5 - Carregar agenda\n");
        printf("6 - Mudar contato da agenda\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("Opcao escolhida: %d\n", opcao);

        switch (opcao) {
            case 1:
                printf("Pessoal ou trabalho? (0 - pessoal, 1 - trabalho): ");
                scanf("%d", &opcao2);
                if (opcao2 == 0) {
                    criar(contatos, &pos, 0);
                } else if (opcao2 == 1) {
                    criar(contatos_trabalho, &pos_trabalho, 1);
                }
                break;
            case 2:
                printf("Pessoal ou trabalho? (0 - pessoal, 1 - trabalho): ");
                scanf("%d", &opcao2);
                if (opcao2 == 0) {
                    char telefone_a_remover[20];
                    printf("Digite o número de telefone do contato que deseja remover: ");
                    scanf("%19s", telefone_a_remover);
                    deletar(contatos, telefone_a_remover, &pos, 0);
                } else if (opcao2 == 1) {
                    char telefone_a_remover[20];
                    printf("Digite o número de telefone do contato que deseja remover: ");
                    scanf("%19s", telefone_a_remover);
                    deletar(contatos_trabalho, telefone_a_remover, &pos_trabalho, 1);
                }
                break;
            case 3:
                printf("Pessoal ou trabalho? (0 - pessoal, 1 - trabalho): ");
                scanf("%d", &opcao2);
                if (opcao2 == 0) {
                    listar(contatos, &pos, 0);
                } else if (opcao2 == 1) {
                    listar(contatos_trabalho, &pos_trabalho, 1);
                }
                break;
            case 4:
                salvar(contatos, &pos, TOTAL);
                break;
            case 5:
                carregar(contatos, &pos, TOTAL);
                break;
            case 6:
                printf("Pessoal ou trabalho? (0 - pessoal, 1 - trabalho): ");
                scanf("%d", &opcao2);
                if (opcao2 == 0) {
                    mudar(contatos, &pos, 0, TOTAL);
                } else if (opcao2 == 1) {
                    mudar(contatos_trabalho, &pos_trabalho, 1, TOTAL);
                }
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