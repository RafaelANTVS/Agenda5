#define TOTAL 255

typedef struct {
    char nome[100];
    char email[100];
    char telefone[20];
} Agenda;



typedef enum {OK, MAX_AGENDA, SEM_CONTATOS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, AGENDA_LOTADA, TELEFONE_EXISTENTE} ERROS;

ERROS criar(Agenda contatos[], int *pos, int type);
ERROS deletar(Agenda contatos[], char *telefone, int *pos, int type);
ERROS listar(Agenda contatos[], int *pos, int type);
ERROS salvar(Agenda contatos[], int *pos, int tamanho);
ERROS carregar(Agenda contatos[], int *pos, int tamanho);
ERROS mudar(Agenda contatos[], int *pos, int tamanho, int type);

void printAgenda(Agenda contatos, int pos, int type);
void clearBuffer();
