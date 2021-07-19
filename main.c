#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXAV 2000
#define MAXNOME 100
#define MAX 2200

//Continuar consultanome, fazer primeiro com o primeiro em comum, depois procurar fazer com buscas mais específicas.

typedef struct{
    char nome[MAXNOME];
    char avaliacao[MAXAV];
    char nota[4];
    char parte[5];
    double nota_d;
    int parte_i;
}midia;

char apelido[100];

void tela_inicial();
int menu();
bool verificanota(midia conteudo);
bool verificatamanho(midia conteudo);
void registralivro(midia conteudo);
void registrafilme(midia conteudo);
void registraserie(midia conteudo);
void registrajogo(midia conteudo);
void listacategoria();
void consultanome();

int main(){

    int opcoes;
    midia conteudo;

    tela_inicial();

    do{
        system("pause");
        system("cls");
        opcoes = menu();
        if(opcoes == 1){
            registralivro(conteudo);
        }else if(opcoes == 2){
            registrafilme(conteudo);
        }else if(opcoes == 3){
            registraserie(conteudo);
        }else if(opcoes == 4){
            registrajogo(conteudo);
        }else if(opcoes == 5){
            listacategoria();
        }else if(opcoes == 6){
            consultanome();
        }else if(opcoes == 7){
            //excluimidia();
        }else if(opcoes == 8){
            //addcomment();
        }else if(opcoes == 9){
            //addelse();
        }else if(opcoes != 10){
            printf("10 para fechar o programa.\n\n");
            system("pause");
        }
    }while(opcoes != 10);

    return 0;
}

//---------Tela Inicial----------------------------------------------------------------------------------------
void tela_inicial()// A tela inicial mostrada antes do menu para informacoes sobre o programa
{
    FILE *nome;

    nome = fopen("nome.txt", "rb");

    if(nome) {
        fgets(apelido, 100, nome);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("Bem-vindo,");
        printf(" %s\n\n\n\n\n\n\n\n\n\n\n\n\n", apelido);
        system("pause");
        system("cls");
        printf("\nEsse eh o seu ambiente para ser o critico que quiser :)\n\n");
        printf("Nesse programa voce podera cadastrar e\narmazenar dados de filmes, series, jogos e livros.\n\n");
        printf("Cada categoria sera armazenada a partir de:\n");
        printf("- Seu nome;\n");
        printf("- Sua duracao;\n- Assistido/lido ou nao;\n");
        printf("- A data que foi consumido;\n- Sua avaliacao;\n");
        printf("- E comentarios adicionais.\n\n");
        printf("E nao se preocupe quanto as informacoes, voce sempre podera atualiza-las ;)\n\n");
        printf("Agora vamos as opcoes:\n\n");
    }else{
        fclose(nome);
        nome = fopen("nome.txt", "a+b");

        printf("Qual eh o seu apelido? Sera usado no app: ");
        fgets(apelido, sizeof(apelido), stdin);
        fprintf(nome,"%s", apelido);
        fclose(nome);

        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("Bem-vindo,");
        printf(" %s\n\n\n\n\n\n\n\n\n\n\n\n\n", apelido);
        system("pause");
        system("cls");
        printf("\nEsse eh o seu ambiente para ser o critico que quiser :)\n\n");
        printf("Nesse programa voce podera cadastrar e\narmazenar dados de filmes, series, jogos e livros.\n\n");
        printf("Cada categoria sera armazenada a partir de:\n");
        printf("- Seu nome;\n");
        printf("- Sua duracao;\n- Assistido/lido ou nao;\n");
        printf("- A data que foi consumido;\n- Sua avaliacao;\n");
        printf("- E comentarios adicionais.\n\n");
        printf("Agora vamos as opcoes:\n\n");
    }
}

//---------Menu------------------------------------------------------------------------------------------------
int menu() // Funcao que retorna o menu para a funcao principal
{
    int i;
    char opcoes[2], *ptr;
    int opcoes_i;

    printf("\n");
    for(i = 0; i < 50; i++) // Printa as barras que decoram o menu
    {
        printf("%c", 254);
    }
    printf("\n");
    printf("1) Registrar Livro\n");
    printf("2) Registrar Filme\n");
    printf("3) Registrar Serie\n");
    printf("4) Registrar Jogo\n");
    printf("5) Listar por Categoria\n");
    printf("6) Consultar por Nome\n");
    printf("7) Excluir ou Atualizar Conteudo\n");
    printf("8) Adicionar Comentario\n");
    printf("9) Lista de Desejos\n");
    printf("10) Encerrar Programa\n");
    for(i = 0; i < 50; i++)
    {
        printf("%c", 254);
    }
    printf("\n\nDigite a opcao desejada: ");
    fflush(stdin);
    scanf("%[^\n]s", opcoes);
    opcoes_i = strtol(opcoes, &ptr, 10);

    return opcoes_i;
}

//--------Verifica Nota----------------------------------------------------------------------------------------
bool verificanota(midia conteudo){
    int erro = 0;

    for(int i = 0; i < strlen(conteudo.nota); i++) {
        if(conteudo.nota[i] >= 'A' && conteudo.nota[i] <= 'Z'){
            erro++;
        }
    }
    if(erro > 0){
        return false;
    }else if(conteudo.nota_d >= 0 && conteudo.nota_d <= 10){
        return true;
    }

    return false;

}

//--------Verifica Tamanho-------------------------------------------------------------------------------------
bool verificatamanho(midia conteudo){
    int erro = 0;

    for(int i = 0; i < strlen(conteudo.parte); i++) {
        if(conteudo.parte[i] >= 'A' && conteudo.parte[i] <= 'Z'){
            erro++;
        }
    }
    if(erro > 0){
        return false;
    }else if(conteudo.parte_i >= 0 && conteudo.parte_i <= 10){
        return true;
    }

    return false;

}

//--------Registra Livro---------------------------------------------------------------------------------------
void registralivro(midia conteudo){
    FILE *livros;
    char opcao[2];
    char *ptr;

    livros = fopen("livros.txt", "a+b");
    printf("\n");
    if(livros){
        do{
            printf("Escreva o nome do livro que deseja registrar: ");
            fflush(stdin);
            scanf("%[^\n]s", conteudo.nome);
            strupr(conteudo.nome);
        }while(strlen(conteudo.nome) < 1);
       do{
            printf("Ja terminaste?(S/N): ");
            fflush(stdin);
            scanf("%[^\n]s", opcao);
            strupr(opcao);
        }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
        if(strcmp(opcao, "N") == 0){
            do{
                printf("Faca seu comentario sobre o que achou ate agora do livro: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.avaliacao);
            }while(strlen(conteudo.avaliacao) < 3);
            do{
                printf("Qual nota daria?(0.0-10.0): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.nota);
                strupr(conteudo.nota);
                conteudo.nota_d = strtod(conteudo.nota, &ptr);
            }while(verificanota(conteudo)==false);
            do{
                printf("Leu ate que parte?(num da pag): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.parte);
                conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
            }while(verificatamanho(conteudo)==false);
            do{
                printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "S") == 0){
                fseek(livros, 0, SEEK_END);
                fprintf(livros,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                , conteudo.nota_d, conteudo.parte_i);
                printf("Livro %s registrado com sucesso!\n\n", conteudo.nome);
            }else if(strcmp(opcao, "N") == 0){
                printf("Livro %s nao foi registrado.\n\n", conteudo.nome);
            }
        }else if(strcmp(opcao, "S") == 0){
            do{
                printf("Faca seu comentario sobre o livro: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.avaliacao);
            }while(strlen(conteudo.avaliacao) < 3);
            do{
                printf("Qual nota daria?(0.0-10.0): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.nota);
                conteudo.nota_d = strtod(conteudo.nota, &ptr);
            }while(verificanota(conteudo)==false);
            do{
                printf("Ele tem quantas paginas no total?: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.parte);
                conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
            }while(verificatamanho(conteudo)==false);
            do{
                printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "S") == 0){
                fseek(livros, 0, SEEK_END);
                fprintf(livros,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                        , conteudo.nota_d, conteudo.parte_i);
                printf("Livro %s registrado com sucesso!\n\n", conteudo.nome);
            }else if(strcmp(opcao, "N") == 0){
                printf("Livro %s nao foi registrado.\n\n", conteudo.nome);
            }
        }
    }else{
        printf("\nArquivo de livros nao foi aberto\n\n");
    }

    fclose(livros);
}

//--------Registra Filme---------------------------------------------------------------------------------------
void registrafilme(midia conteudo){
    FILE *filmes;
    char opcao[2];
    char *ptr;

    filmes = fopen("filmes.txt", "a+b");
    printf("\n");
    if(filmes){
        do{
            printf("Escreva o nome do filme que deseja registrar: ");
            fflush(stdin);
            scanf("%[^\n]s", conteudo.nome);
        }while(strlen(conteudo.nome) < 1);
        strupr(conteudo.nome);
        do{
            printf("Ja terminaste?(S/N): ");
            fflush(stdin);
            scanf("%[^\n]s", opcao);
            strupr(opcao);
        }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
        if(strcmp(opcao, "N") == 0){
            do{
                printf("Faca seu comentario sobre o filme: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.avaliacao);
            }while(strlen(conteudo.avaliacao) < 3);
            do{
                printf("Qual nota daria?(0.0-10.0): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.nota);
                conteudo.nota_d = strtod(conteudo.nota, &ptr);
            }while(verificanota(conteudo)==false);
            do{
                printf("Viu ate que parte?(minutos): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.parte);
                conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
            }while(verificatamanho(conteudo)==false);
            conteudo.nota_d = strtol(conteudo.parte, &ptr, 10);
            do{
                printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "S") == 0){
                fseek(filmes, 0, SEEK_END);
                fprintf(filmes,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                        , conteudo.nota_d, conteudo.parte_i);
                printf("%s registrado com sucesso!\n\n", conteudo.nome);
            }else if(strcmp(opcao, "N") == 0){
                printf("%s nao foi registrado.\n\n", conteudo.nome);
            }
        }else if(strcmp(opcao, "S") == 0){
            do{
                printf("Faca seu comentario sobre o filme: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.avaliacao);
            }while(strlen(conteudo.avaliacao) < 3);
            do{
                printf("Qual nota daria?(0.0-10.0): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.nota);
                conteudo.nota_d = strtod(conteudo.nota, &ptr);
            }while(verificanota(conteudo)==false);
            do{
                printf("Ele tem quantos minutos?: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.parte);
                conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
            }while(verificatamanho(conteudo)==false);
            do{
                printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "S") == 0){
                fseek(filmes, 0, SEEK_END);
                fprintf(filmes,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                        , conteudo.nota_d, conteudo.parte_i);
                printf("%s registrado com sucesso!\n\n", conteudo.nome);
            }else if(strcmp(opcao, "N") == 0){
                printf("%s nao foi registrado.\n\n", conteudo.nome);
            }
        }
    }else{
        printf("\nArquivo de filmes nao foi aberto\n\n");
    }

    fclose(filmes);
}

//--------Registra Serie---------------------------------------------------------------------------------------
void registraserie(midia conteudo){
    FILE *series;
    char opcao[2];
    char *ptr;

    series = fopen("series.txt", "a+b");
    printf("\n");
    if(series){
        do{
            printf("Escreva o nome da serie que deseja registrar: ");
            fflush(stdin);
            scanf("%[^\n]s", conteudo.nome);
        }while(strlen(conteudo.nome) < 1);
        strupr(conteudo.nome);
        do{
            printf("Ja terminaste?(S/N): ");
            fflush(stdin);
            scanf("%[^\n]s", opcao);
            strupr(opcao);
        }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
        if(strcmp(opcao, "N") == 0){
            do{
                printf("Faca seu comentario sobre a serie ate agora: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.avaliacao);
            }while(strlen(conteudo.avaliacao) < 3);
            do{
                printf("Qual nota daria?(0.0-10.0): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.nota);
                conteudo.nota_d = strtod(conteudo.nota, &ptr);
            }while(verificanota(conteudo)==false);
            do{
                printf("Viu ate que ep?(conte todos os eps ate o atual): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.parte);
                conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
            }while(verificatamanho(conteudo)==false);
            do{
                printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "S") == 0){
                fseek(series, 0, SEEK_END);
                fprintf(series,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                        , conteudo.nota_d, conteudo.parte_i);
                printf("%s registrada com sucesso!\n\n", conteudo.nome);
            }else if(strcmp(opcao, "N") == 0){
                printf("%s nao foi registrada.\n\n", conteudo.nome);
            }
        }else if(strcmp(opcao, "S") == 0){
            do{
                printf("Faca seu comentario sobre a serie: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.avaliacao);
            }while(strlen(conteudo.avaliacao) < 3);
            do{
                printf("Qual nota daria?(0.0-10.0): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.nota);
                conteudo.nota_d = strtod(conteudo.nota, &ptr);
            }while(verificanota(conteudo)==false);
            do{
                printf("Quantos eps no total?: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.parte);
                conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
            }while(verificatamanho(conteudo)==false);
            do{
                printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "S") == 0){
                fseek(series, 0, SEEK_END);
                fprintf(series,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                        , conteudo.nota_d, conteudo.parte_i);
                printf("%s registrada com sucesso!\n\n", conteudo.nome);
            }else if(strcmp(opcao, "N") == 0){
                printf("%s nao foi registrada.\n\n", conteudo.nome);
            }
        }
    }else{
        printf("\nArquivo de series nao foi aberto\n\n");
    }

    fclose(series);
}

//--------Registra Jogo----------------------------------------------------------------------------------------
void registrajogo(midia conteudo){
    FILE *jogos;
    char opcao[2];
    char *ptr;

    jogos = fopen("jogos.txt", "a+b");
    printf("\n");
    if(jogos){
        do{
            printf("Escreva o nome do jogo que deseja registrar: ");
            fflush(stdin);
            scanf("%[^\n]s", conteudo.nome);
        }while(strlen(conteudo.nome) < 1);
        strupr(conteudo.nome);
        do{
            printf("Quer avaliar o modo historia(se nao tem, digite N)?(S/N): ");
            fflush(stdin);
            scanf("%[^\n]s", opcao);
            strupr(opcao);
        }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
        if(strcmp(opcao, "N") == 0){
            do{
                printf("Faca seu comentario sobre o jogo: ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.avaliacao);
            }while(strlen(conteudo.avaliacao) < 3);
            do{
                printf("Qual nota daria?(0.0-10.0): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.nota);
                conteudo.nota_d = strtod(conteudo.nota, &ptr);
            }while(verificanota(conteudo)==false);
            do{
                printf("Digite o numero de qual seria seu ranking no jogo ate agora"
                       "\n(ex.:ferro = 0, bronze = 1): ");
                fflush(stdin);
                scanf("%[^\n]s", conteudo.parte);
                conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
            }while(verificatamanho(conteudo)==false);
            do{
                printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "S") == 0){
                fseek(jogos, 0, SEEK_END);
                fprintf(jogos,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                        , conteudo.nota_d, conteudo.parte_i);
                printf("%s registrado com sucesso!\n\n", conteudo.nome);
            }else if(strcmp(opcao, "N") == 0){
                printf("%s nao foi registrado.\n\n", conteudo.nome);
            }
        }else if(strcmp(opcao, "S") == 0){
            do{
                printf("Ja zeraste?(S/N): ");
                fflush(stdin);
                scanf("%[^\n]s", opcao);
                strupr(opcao);
            }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
            if(strcmp(opcao, "N") == 0){
                do{
                    printf("Faca seu comentario sobre a campanha ate agora: ");
                    fflush(stdin);
                    scanf("%[^\n]s", conteudo.avaliacao);
                }while(strlen(conteudo.avaliacao) < 3);
                do{
                    printf("Qual nota daria?(0.0-10.0): ");
                    fflush(stdin);
                    scanf("%[^\n]s", conteudo.nota);
                    conteudo.nota_d = strtod(conteudo.nota, &ptr);
                }while(verificanota(conteudo)==false);
                do{
                    printf("Ja passou por quantas fases?: ");
                    fflush(stdin);
                    scanf("%[^\n]s", conteudo.parte);
                    conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
                }while(verificatamanho(conteudo)==false);
                do{
                    printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                    fflush(stdin);
                    scanf("%[^\n]s", opcao);
                    strupr(opcao);
                }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
                if(strcmp(opcao, "S") == 0){
                    fseek(jogos, 0, SEEK_END);
                    fprintf(jogos,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                            , conteudo.nota_d, conteudo.parte_i);
                    printf("%s registrado com sucesso!\n\n", conteudo.nome);
                }else if(strcmp(opcao, "N") == 0){
                    printf("%s nao foi registrado.\n\n", conteudo.nome);
                }
            }else if(strcmp(opcao, "S") == 0){
                do{
                    printf("Faca seu comentario sobre a campanha do jogo: ");
                    fflush(stdin);
                    scanf("%[^\n]s", conteudo.avaliacao);
                }while(strlen(conteudo.avaliacao) < 3);
                do{
                    printf("Qual nota daria?(0.0-10.0): ");
                    fflush(stdin);
                    scanf("%[^\n]s", conteudo.nota);
                    conteudo.nota_d = strtod(conteudo.nota, &ptr);
                }while(verificanota(conteudo)==false);
                do{
                    printf("O jogo tem quantas fases na campanha principal?: ");
                    fflush(stdin);
                    scanf("%[^\n]s", conteudo.parte);
                    conteudo.parte_i = strtol(conteudo.parte, &ptr, 1000);
                }while(verificatamanho(conteudo)==false);
                do{
                    printf("Deseja mesmo registrar %s?(S/N): ", conteudo.nome);
                    fflush(stdin);
                    scanf("%[^\n]s", opcao);
                    strupr(opcao);
                }while(strcmp(opcao, "N") != 0 && strcmp(opcao, "S") != 0);
                if(strcmp(opcao, "S") == 0){
                    fseek(jogos, 0, SEEK_END);
                    fprintf(jogos,"%s;%s;%.1lf;%d\n", conteudo.nome, conteudo.avaliacao
                            , conteudo.nota_d, conteudo.parte_i);
                    printf("%s registrado com sucesso!\n\n", conteudo.nome);
                }else if(strcmp(opcao, "N") == 0){
                    printf("%s nao foi registrado.\n\n", conteudo.nome);
                }
            }
        }
    }else{
        printf("\nArquivo de jogos nao foi aberto\n\n");
    }

    fclose(jogos);
}

//--------Lista Categoria--------------------------------------------------------------------------------------
void listacategoria(){
    FILE *midia;
    char opcao[2];
    int opcai;
    char *ptr, *token;
    char avaliacao[MAX];
    int i;

    do{
        printf("\nSelecione a opcao para listagem:\n");
        printf("1-Livros\n2-Filmes\n3-Series\n4-Jogos\n");
        fflush(stdin);
        scanf("%[^\n]", opcao);
        opcai = strtol(opcao, &ptr, 10);
    }while((opcai!=1)&&(opcai!=2)&&(opcai!=3)&&(opcai!=4));

    system("cls");
    if(opcai == 1){
        midia = fopen("livros.txt", "a+b");
        if(midia){
            printf("Seguem todos os livros registrados e suas informacoes: \n\n");
            while(fgets(avaliacao, MAX, midia)){
                token = strtok(avaliacao, ";");
                i = 0;
                while(token != NULL){
                    if(i == 0){
                        printf("Livro: ");
                    }else if(i == 1){
                        printf("Avaliacao: ");
                    }else if(i == 2){
                        printf("Nota: ");
                    }else if(i == 3){
                        printf("Paginas lidas ou totais: ");
                    }
                    printf("%s\n", token);
                    token = strtok(NULL, ";");
                    i++;
                }
            }
        }else{
            printf("Nao foi possivel abrir o arquivo de livros.\n");
        }
    }else if(opcai == 2){
        midia = fopen("filmes.txt", "a+b");
        if(midia){
            printf("Seguem todos os filmes registrados e suas informacoes: \n\n");
            while(fgets(avaliacao, MAX, midia)){
                token = strtok(avaliacao, ";");
                i = 0;
                while(token != NULL){
                    if(i == 0){
                        printf("Filme: ");
                    }else if(i == 1){
                        printf("Avaliacao: ");
                    }else if(i == 2){
                        printf("Nota: ");
                    }else if(i == 3){
                        printf("Minutos totais: ");
                    }
                    printf("%s\n", token);
                    token = strtok(NULL, ";");
                    i++;
                }
            }
        }else{
            printf("Nao foi possivel abrir o arquivo de filmes.\n");
        }
    }else if(opcai == 3){
        midia = fopen("series.txt", "a+b");
        if(midia){
            printf("Seguem todos as series registradas e suas informacoes: \n\n");
            while(fgets(avaliacao, MAX, midia)){
                token = strtok(avaliacao, ";");
                i = 0;
                while(token != NULL){
                    if(i == 0){
                        printf("Serie: ");
                    }else if(i == 1){
                        printf("Avaliacao: ");
                    }else if(i == 2){
                        printf("Nota: ");
                    }else if(i == 3){
                        printf("Episodios vistos ou totais: ");
                    }
                    printf("%s\n", token);
                    token = strtok(NULL, ";");
                    i++;
                }
            }
        }else{
            printf("Nao foi possivel abrir o arquivo de series.\n");
        }
    }else if(opcai == 4){
        midia = fopen("jogos.txt", "a+b");
        if(midia){
            printf("Seguem todos os jogos registrados e suas informacoes: \n\n");
            while(fgets(avaliacao, MAX, midia)){
                token = strtok(avaliacao, ";");
                i = 0;
                while(token != NULL){
                    if(i == 0){
                        printf("Jogo: ");
                    }else if(i == 1){
                        printf("Avaliacao: ");
                    }else if(i == 2){
                        printf("Nota: ");
                    }else if(i == 3){
                        printf("Ranking/fases concluídas ou totais: ");
                    }
                    printf("%s\n", token);
                    token = strtok(NULL, ";");
                    i++;
                }
            }
        }else{
            printf("Nao foi possivel abrir o arquivo de jogos.\n");
        }
    }
}

//--------Consulta Nome----------------------------------------------------------------------------------------
void consultanome(){
    FILE *midia;
    char opcao[2];
    char *ptr;
    int opcai;

    do{
        printf("\nSelecione a opcao para consulta:\n");
        printf("1-Livro\n2-Filme\n3-Serie\n4-Jogo\n");
        fflush(stdin);
        scanf("%[^\n]", opcao);
        opcai = strtol(opcao, &ptr, 10);
    }while((opcai!=1)&&(opcai!=2)&&(opcai!=3)&&(opcai!=4));

}
