#define TOTAL 255

typedef struct Contato {
    char nome[100];
    char numero[11];
    char email[100];
} Contato;

typedef enum {OK, MAX_CONTATOS, SEM_CONTATOS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, NUMERO_INVALIDO} ERROS;

typedef ERROS (*funcao)(Contato[], int*);

int validar_email(char email[]);
int validar_numero(char numero[]);

ERROS criar(Contato contatos[], int *pos);
ERROS deletar(Contato contatos[], int *pos);
ERROS listar(Contato contatos[], int *pos);
ERROS salvar(Contato contatos[], int *pos);
ERROS carregar(Contato contatos[], int *pos);

void clearBuffer();
