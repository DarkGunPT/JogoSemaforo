//
// TP Programação - Jogo do Semáforo - Realizado por Nuno Gabriel Tavares Honório a2019126457
//

#include <stdlib.h>
#include <stdio.h>
#include "jogo.h"
#include "utils.h"
// Função que apresenta os menus
void menu2(int escolha){
    switch (escolha){
        case 1:
            printf("1 - Jogar jogador x jogador\n");
            printf("2 - Jogar jogador x computador\n");
            printf("3 - Sair \n");
            printf("Opcao: ");
            break;
        case 2:
            printf("1 - Jogar peca\n");
            printf("2 - Jogar pedra\n");
            printf("3 - Ver jogadas anteriores\n");
            printf("4 - Acrescentar linha\n");
            printf("5 - Acrescentar coluna\n");
            printf("6 - Gravar\n");
            printf("7 - Sair\n");
            printf("Opcao: ");
            break;
        case 3:
            printf("1 - Comecar de novo\n");
            printf("2 - Sair\n");
            printf("Opcao: ");
            break;
        case 4:
            printf("1 - Jogar peca\n");
            printf("2 - Gravar\n");
            printf("3 - Sair\n");
            printf("Opcao: ");
            break;
        default:
            printf("Menu indisponível !!");
            break;
    }
}
// Mostrar tabuleiro
void mostrarTab(Tabuleiro *tab){
    printf("  ");
    for(int i = 1; i <=tab->colunas; i++){
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < tab->linhas; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < tab->colunas; j++) {
            printf("%c ", tab->tab[i][j]);
        }
        printf("\n");
    }
}
// Mudar a cor do tabuleiro
int mudarCor(Tabuleiro *tab, Jogo *jogo){
    int jogada=0;
                if (tab->tab[jogo->linhajogada][jogo->colunajogada] == 'x') {
                    tab->tab[jogo->linhajogada][jogo->colunajogada] = 'G';
                    jogada=1;
                    return jogada;
                } else if (tab->tab[jogo->linhajogada][jogo->colunajogada] == 'G') {
                    tab->tab[jogo->linhajogada][jogo->colunajogada] = 'Y';
                    jogada=1;
                    return jogada;
                } else if (tab->tab[jogo->linhajogada][jogo->colunajogada] == 'Y') {
                    tab->tab[jogo->linhajogada][jogo->colunajogada] = 'R';
                    jogada=1;
                    return jogada;
                }else if(tab->tab[jogo->linhajogada][jogo->colunajogada] == 'O'){
                    printf("\n");
                    printf("Celula encontra-se com uma pedra, escolha outra jogada!\n");
                    return jogada;
                } else {
                    printf("\n");
                    printf("Celula ja se encontra no vermelho, escolha outra jogada!\n");
                    return jogada;
                }
}
// Verificações  e jogar do bot
int jogarAutomatico(Tabuleiro *tab, Jogo *jogo){
    int jogada=0;
    jogo->linhajogada= intUniformRnd(0,tab->linhas-1);
    jogo->colunajogada= intUniformRnd(0,tab->colunas-1);
    if (tab->tab[jogo->linhajogada][jogo->colunajogada] == 'x') {
        tab->tab[jogo->linhajogada][jogo->colunajogada] = 'G';
        jogada=1;
        return jogada;
    } else if (tab->tab[jogo->linhajogada][jogo->colunajogada] == 'G') {
        tab->tab[jogo->linhajogada][jogo->colunajogada] = 'Y';
        jogada=1;
        return jogada;
    } else if (tab->tab[jogo->linhajogada][jogo->colunajogada] == 'Y') {
        tab->tab[jogo->linhajogada][jogo->colunajogada] = 'R';
        jogada=1;
        return jogada;
    }else if(tab->tab[jogo->linhajogada][jogo->colunajogada] == 'O'){
        printf("\n");
        printf("Celula encontra-se com uma pedra, escolha outra jogada!\n");
        return jogada;
    } else {
        printf("\n");
        printf("Celula ja se encontra no vermelho, escolha outra jogada!\n");
        return jogada;
    }
}
// Cria a tabela inicial
void criarTab(Tabuleiro *tab){

    tab->linhas= tab->colunas = intUniformRnd(3, 5);
    tab->tab = malloc(sizeof(char*)*tab->linhas);
    if(tab->tab==NULL){
        printf("Erro !");
        exit(0);
    }
    for(int i=0; i<tab->linhas; i++){
        tab->tab[i]= malloc(sizeof (char)*tab->colunas);
        if(tab->tab[i] == NULL){
            printf("Erro !");
            exit(0);
        }
    }
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas; j++) {
            tab->tab[i][j] = 'x';
        }
    }
}
// Inicializa os Jogadores segundo o modo de jogo
void inicializarJogadores(int modo, struct jogador *pjogador1, struct jogador *pjogador2){
    pjogador1->nome='A';
    pjogador2->nome='B';
    if(modo==1){
        pjogador1->pedra=1;
        pjogador2->pedra=1;
        pjogador1->adicionar=2;
        pjogador2->adicionar=2;
    }else if(modo==2){
        pjogador1->pedra=1;
        pjogador2->pedra=0;
        pjogador1->adicionar=2;
        pjogador2->adicionar=0;
    }
}
// Troca de jogador no final do turno
void trocarJogador(Jogo *jogo){
    if(jogo->jogadoratual==0){
        jogo->jogadoratual=1;
    }else{
        jogo->jogadoratual=0;
    }
}
// Le a jogada e verifica se está dentro do tabuleiro
void lerJogada(Tabuleiro *tab, Jogo *jogo){
    do{
        printf("Insira a linha em que pretende jogar: ");
        scanf("%d", &jogo->linhajogada);
    }while(jogo->linhajogada>tab->linhas || jogo->linhajogada<1);
    do{
        printf("Insira a coluna em que pretende jogar: ");
        scanf("%d", &jogo->colunajogada);
    }while(jogo->colunajogada>tab->colunas || jogo->colunajogada<1);
    printf("\n");
}
// Apresenta os dados do turno e quem é a jogar
void apresentarDados(Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *tab){
            printf("=== Jogada %d ===\n", tab->jogada);
        if(jogo->jogadoratual==0){
            printf("=== Vez do jogador %c jogar ===\n", jogador1->nome);
            printf("=== Adicionar linhas ou colunas disponiveis: %d ===\n", jogador1->adicionar);
            printf("=== Pedras disponiveis: %d ===\n", jogador1->pedra);
        }else{
            printf("=== Vez do jogador %c jogar ===\n", jogador2->nome);
            printf("=== Adicionar linhas ou colunas disponiveis: %d ===\n", jogador2->adicionar);
            printf("=== Pedras disponiveis: %d ===\n", jogador2->pedra);
        }
};
// Joga pedra na coluna escolhida
int jogarPedra(Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *tab){
    if (tab->tab[jogo->linhajogada][jogo->colunajogada] == 'x') {
        if(jogo->jogadoratual==0 && jogador1->pedra>0){
            tab->tab[jogo->linhajogada][jogo->colunajogada] = 'O';
            jogador1->pedra=0;
            return 1;
        }else if(jogo->jogadoratual==1 && jogador2->pedra>0){
            tab->tab[jogo->linhajogada][jogo->colunajogada] = 'O';
            jogador2->pedra=0;
            return 1;
        }else{
            printf("O jogador ja nao apresenta pedras suficientes !");
            return 0;
        }
    }else{
        printf("A celula que tentou jogar a pedra nao se encontra vazia !\n");
        return 0;
    }
}
// Verifica a Linha
int verificaLinha(Tabuleiro *tab){
    int iguais=1;
    for(int i=0; i<tab->linhas; i++){
        for(int j=0; j<tab->colunas-1; j++){
            if(tab->tab[i][j]==tab->tab[i][j+1] && tab->tab[i][j]!='x')
                iguais++;
        }
        if(iguais==tab->colunas){
            return 1;
        }else{
            iguais=1;
        }
    }
    return 0;
}
// Verifica a coluna
int verificaColuna(Tabuleiro *tab){
    int iguais=1;
    for(int i=0; i<tab->colunas; i++){
        for(int j=0; j<tab->linhas-1; j++){
            if(tab->tab[j][i]==tab->tab[j+1][i] && tab->tab[j][i]!='x')
                iguais++;
        }
        if(iguais==tab->linhas){
            return 1;
        }else{
            iguais=1;
        }
    }
    return 0;
}
// Verifica a diagonal
int verificaDiagonal(Tabuleiro *tab) {
    int iguais = 1;
    if(tab->linhas==tab->colunas){
        for (int i = 0; i < tab->colunas-1; i++) {
            if (tab->tab[i][i] == tab->tab[i+1][i+1] && tab->tab[i][i]!='x') {
                iguais++;
            } else
                iguais = 0;
        }
        if (iguais == tab->colunas) {
            return 1;
        }
        iguais=1;
        for (int j = 0, i = tab->colunas - 1; i > 0; i--, j++) {
            if (tab->tab[j][i] == tab->tab[j+1][i-1] && tab->tab[j][i]!='x') {
                iguais++;
            } else
                iguais = 1;
        }

        if (iguais == tab->colunas) {
            return 1;
        }
    }
    return 0;
}
// Escreve jogada atual para a lista ligada
pTabuleiro guardaJogadas(Tabuleiro *tab, Tabuleiro *inicial){
    Tabuleiro *aux=NULL;
    if(inicial==NULL){
        inicial = malloc(sizeof (Tabuleiro));
        inicial->linhas=tab->linhas;
        inicial->colunas=tab->colunas;
        inicial->jogada=tab->jogada;
        inicial->tab=malloc(sizeof (char*) *inicial->linhas);
        for(int i=0; i<inicial->linhas; i++){
            inicial->tab[i]= malloc(sizeof (char) *inicial->colunas);
        }
        for(int i=0; i<inicial->linhas; i++){
            for(int j=0; j<inicial->colunas; j++){
                inicial->tab[i][j]=tab->tab[i][j];
            }
        }
    }else{
        aux=inicial;
        while(aux->prox!=NULL)
            aux=aux->prox;

        aux->prox = malloc(sizeof(Tabuleiro));
        aux=aux->prox;
        aux->linhas = tab->linhas;
        aux->colunas = tab->colunas;
        aux->jogada=tab->jogada;
        aux->tab = malloc(sizeof(char*)*aux->linhas);
        for(int i=0; i<aux->linhas; i++){
            aux->tab[i]= malloc(sizeof (char)*aux->colunas);
        }
        for(int i=0;i<aux->linhas;i++){
            for(int j=0;j<aux->colunas;j++){
                aux->tab[i][j] = tab->tab[i][j];
            }
        }
        aux->prox=NULL;
    }
    return inicial;
}
// Escreve a lista para o ficheiro texto
void writeToFile(Tabuleiro *inicial)
{
    FILE * fptr;
    char nome[20], nomec[20];
    printf("Insira um nome para guardar historico: ");
    scanf("%s", nome);
    snprintf(nomec,sizeof(nomec),"historicos/%s.txt", nome);
    fptr = fopen(nomec, "w");
    if(inicial==NULL)
    {
        printf("Error\n");
    }else
    {
        fprintf(fptr, "=== Historico do jogo ===");
        while(inicial != NULL)
        {
            fprintf(fptr, "\n=== Jogada %d ===\n", inicial->jogada);
            fprintf(fptr,"  ");
            for(int i = 1; i <=inicial->colunas; i++){
                fprintf(fptr,"%d ", i);
            }
            fprintf(fptr,"\n");
            for (int i = 0; i < inicial->linhas; i++) {
                fprintf(fptr,"%d ", i+1);
                for (int j = 0; j < inicial->colunas; j++) {
                    fprintf(fptr,"%c ", inicial->tab[i][j]);
                }
                fprintf(fptr,"\n");
            }
            inicial = inicial->prox;
        }
    }
    fclose(fptr);
    printf("\n");
}
// Verificar se existe o bin ou não
int verificarFicheiro(){
    FILE *fh = fopen("save.bin", "rb");
    if(fh==NULL){
        return 0;
    }
    return 1;
}
// Gravar o save do jogo
void guardar(Tabuleiro *tab, Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *inicial){
    char nomec[20];
    char nome[]="save";
    snprintf(nomec,sizeof(nomec),"%s.bin", nome);
    FILE *fh = fopen (nomec, "wb");
    if (fh == NULL){
        fprintf(stderr, "\nErro a abrir o ficheiro !!\n");
    }else {
        fwrite(&jogo,sizeof (jogo),1,fh);
        fwrite(&jogador1->adicionar, sizeof (int), 1, fh);
        fwrite(&jogador2->adicionar, sizeof (int), 1, fh);
        fwrite(&jogador1->pedra, sizeof (int), 1, fh);
        fwrite(&jogador2->pedra, sizeof (int), 1, fh);
        fwrite(&tab->linhas, sizeof(int), 1, fh);
        fwrite(&tab->colunas, sizeof(int), 1, fh);
        fwrite(&tab->jogada, sizeof(int), 1, fh);
        for(int i=0; i<tab->linhas; i++){
            for(int j=0; j<tab->colunas; j++){
                fwrite(&tab->tab[i][j], sizeof(char), 1, fh);
            }
        }
        while(inicial!=NULL){
            fwrite(&inicial->linhas, sizeof(int), 1, fh);
            fwrite(&inicial->colunas, sizeof(int), 1, fh);
            fwrite(&inicial->jogada, sizeof(int), 1, fh);
            fwrite(&inicial->prox, sizeof(Tabuleiro), 1, fh);
            for (int i = 0; i < inicial->linhas; i++)
                for (int j = 0; j < inicial->colunas; j++)
                    fwrite(&inicial->tab[i][j], sizeof(char), 1, fh);
            inicial = inicial->prox;
        }
    }
    printf("\nJogo guardado com sucesso !!\n");
    fclose(fh);
}
// Carregar o save gravado
pTabuleiro carregar(Tabuleiro *tab, Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *inicial){
    char nomec[20];
    Tabuleiro *aux=NULL;
    char nome[]="save";

    snprintf(nomec,sizeof(nomec),"%s.bin", nome);
    FILE *fh = fopen (nomec, "rb");
        fread(&jogo->modo,sizeof (int),1,fh);
        fread(&jogador1->nome, sizeof (char), 1, fh);
        fread(&jogador2->nome, sizeof (char), 1, fh);
        fread(&jogo->jogadoratual, sizeof (int), 1, fh);
        fread(&jogador1->adicionar, sizeof (int), 1, fh);
        fread(&jogador2->adicionar, sizeof (int), 1, fh);
        fread(&jogador1->pedra, sizeof (int), 1, fh);
        fread(&jogador2->pedra, sizeof (int), 1, fh);
        fread(&tab->linhas, sizeof(int), 1, fh);
        fread(&tab->colunas, sizeof(int), 1, fh);
        fread(&tab->jogada, sizeof(int), 1, fh);
        tab->tab=malloc(sizeof (char*) *tab->linhas);
        for(int i=0; i<tab->linhas; i++){
            tab->tab[i]= malloc(sizeof (char) *tab->colunas);
        }
        for(int i=0; i<tab->linhas; i++){
            for(int j=0; j<tab->colunas; j++){
                fread(&tab->tab[i][j], sizeof(char), 1, fh);
            }
        }
        while(!feof(fh)){
            if(inicial==NULL){
                inicial = malloc(sizeof (Tabuleiro));
                fread(&inicial->linhas, sizeof(int), 1, fh);
                fread(&inicial->colunas, sizeof(int), 1, fh);
                fread(&inicial->jogada, sizeof(int), 1, fh);
                fread(&inicial->prox,sizeof (Tabuleiro),1,fh);
                inicial->tab=malloc(sizeof (char*) *inicial->linhas);
                for(int i=0; i<inicial->linhas; i++){
                    inicial->tab[i]= malloc(sizeof (char) *inicial->colunas);
                }
                for(int i=0; i<inicial->linhas; i++){
                    for(int j=0; j<inicial->colunas; j++){
                        fread(&inicial->tab[i][j], sizeof(char), 1, fh);
                    }
                }
                if(inicial->prox!=NULL){
                    inicial->prox = malloc(sizeof(Tabuleiro));
                }else{
                    fclose(fh);
                    return inicial;
                }
            }else{
                aux=inicial;
                while(aux->prox!=NULL)
                    aux=aux->prox;
                fread(&aux->linhas, sizeof(int), 1, fh);
                fread(&aux->colunas, sizeof(int), 1, fh);
                fread(&aux->jogada, sizeof(int), 1, fh);
                fread(&aux->prox,sizeof (Tabuleiro),1,fh);
                aux->tab = malloc(sizeof(char*)*aux->linhas);
                for(int i=0; i<aux->linhas; i++){
                    aux->tab[i]= malloc(sizeof (char)*aux->colunas);
                }
                for(int i=0;i<aux->linhas;i++){
                    for(int j=0;j<aux->colunas;j++){
                        fread(&aux->tab[i][j], sizeof(char), 1, fh);
                    }
                }
                if(aux->prox==NULL){
                    return inicial;
                }
                aux->prox = malloc(sizeof(Tabuleiro));
            }
        }
        fclose (fh);
        return inicial;
}
// Manutenção do final do jogo
int fimjogo(Jogador *jogador1, Jogador *jogador2, Jogo *jog, Tabuleiro *tab, Tabuleiro *inicial){
    if(jog->jogadoratual==0){
        printf("=== O vencedor foi o jogador %c ===\n", jogador1->nome);
        printf("=== Pedras disponiveis: %d | Adicionar l/c: %d ===\n",jogador1->pedra,jogador1->adicionar);
    }else{
        printf("=== O vencedor foi o jogador %c ===\n", jogador2->nome);
    }
        mostrarTab(tab);
        writeToFile(inicial);
        printf("=== Historico guardado com sucesso !! ===\n");
        libertaTab(tab->linhas,tab->tab);
        printf("Tabuleiro libertado !!\n");
        printf("Lista ligada libertada !!");
        libertaLinked(inicial);
        return 0;
}
// Incrementa no final da jogada
void incJogada(Tabuleiro *tab){
    tab->jogada++;
}
// Mostrar ultimas jogadas
void mostra_jogadas(pTabuleiro p, int jogadas){
    pTabuleiro auxp = p;
    int jogadastotais=1;
    int cont=1;
    while(auxp!=NULL){
        jogadastotais++;
        auxp=auxp->prox;
    }
    int recuos = (jogadastotais-jogadas)-1;
    while(p != NULL){
        if(cont>recuos) {
            printf("Jogada: %d\n", p->jogada);
            mostrarTab(p);
        }
        p = p->prox;
        cont++;
    }
}
// Adicionar linha à matriz
void adicionarLinha(Tabuleiro *tab){
    char **aux;
    tab->linhas++;
    aux = realloc(tab->tab,sizeof(char*)*tab->linhas);
    if(aux==NULL){
        printf("Erro !");
        exit(0);
    }
    aux[tab->linhas-1]= malloc(sizeof (char)*tab->colunas);
    for (int i = 0; i < tab->linhas; i++) {
            aux[tab->linhas-1][i]= 'x';
    }
    tab->tab=aux;
}
// Adicionar coluna à matriz
void adicionarColuna(Tabuleiro *tab){
    char **aux;
    aux=tab->tab;
    if(aux==NULL){
        printf("Erro !");
        exit(0);
    }
    tab->colunas++;
    for(int i=0; i<tab->linhas; i++){
        aux[i]= realloc(tab->tab[i], sizeof(char*)*(tab->colunas));
    }

    for (int i = 0; i < tab->linhas; i++) {
        aux[i][tab->colunas-1]= 'x';
    }
    tab->tab=aux;
}
//Decrementa as pecas adicionar e adiciona linha ao tabuleiro
int xAdicionarLinha(Tabuleiro *tab, Jogo *jogo, Jogador *jogador1, Jogador *jogador2){
    if(jogador1->adicionar>0 && jogo->jogadoratual==0){
        jogador1->adicionar--;
        adicionarLinha(tab);
        return 1;
    }
    else if(jogador2->adicionar>0 && jogo->jogadoratual==1){
        jogador2->adicionar--;
        adicionarLinha(tab);
        return 1;
    }
    return 0;
}
//Decrementa as pecas adicionar e adiciona coluna ao tabuleiro
int xAdicionarColuna(Tabuleiro *tab, Jogo *jogo, Jogador *jogador1, Jogador *jogador2){
    if(jogador1->adicionar>0 && jogo->jogadoratual==0){
        jogador1->adicionar--;
        adicionarColuna(tab);
        return 1;
    }
    else if(jogador2->adicionar>0 && jogo->jogadoratual==1){
        jogador2->adicionar--;
        adicionarColuna(tab);
        return 1;
    }
    return 0;
}
// Manutenção do jogo
int acaojogo(Jogador jogador1, Jogador jogador2, Tabuleiro tab, Jogo jogo, pTabuleiro inicial){
    int passar=1;
    int comando;
    switch (jogo.modo){
        case 1:
            do {
              if (verificaLinha(&tab) == 0 && verificaColuna(&tab) == 0 && verificaDiagonal(&tab) == 0) {
                    mostrarTab(&tab);
                    apresentarDados(&jogador1, &jogador2, &jogo, &tab);
                    menu2(2);
                    scanf("%d", &comando);
                    if (comando == 1) {
                        int jogada;
                        do {
                            lerJogada(&tab, &jogo);
                            jogo.linhajogada = jogo.linhajogada - 1;
                            jogo.colunajogada = jogo.colunajogada - 1;
                            jogada = mudarCor(&tab, &jogo);
                        } while (jogada != 1);
                        inicial=guardaJogadas(&tab, inicial);
                        incJogada(&tab);
                        trocarJogador(&jogo);
                    } else if (comando == 2) {
                        int jogada;
                        do {
                            lerJogada(&tab, &jogo);
                            jogo.linhajogada = jogo.linhajogada - 1;
                            jogo.colunajogada = jogo.colunajogada - 1;
                            jogada = jogarPedra(&jogador1, &jogador2, &jogo, &tab);
                        } while (jogada != 1);
                        inicial=guardaJogadas(&tab, inicial);
                        incJogada(&tab);
                        trocarJogador(&jogo);
                        //insereTabuleiro(tabuleiros, &tab);
                    }else if(comando ==3){
                        int certo=0, jogadas;
                        if(tab.jogada>1){
                            printf("=========================\n\n");

                            do{
                                printf("Quantas jogadas pretende mostrar? \n");
                                scanf("%d", &jogadas);
                                if(jogadas<tab.jogada){
                                    certo=1;
                                    printf("Vao ser mostradas %d jogadas !!\n", jogadas);
                                }else{
                                    printf("Numero de jogadas pedidas superior ao numero de jogadas totais!! \n");
                                }
                            }while(certo!=1);
                            mostra_jogadas(inicial, jogadas);
                            printf("=========================\n\n");
                        }
                    }else if(comando==4){
                        int resultado = xAdicionarLinha(&tab, &jogo,&jogador1,&jogador2);
                        if(resultado == 1){
                            inicial=guardaJogadas(&tab, inicial);
                            incJogada(&tab);
                            trocarJogador(&jogo);
                        }else{
                            printf("Nao apresenta creditos suficientes para aumentar a linha !!");
                        }
                            printf("\n");
                        }else if(comando==5){
                        int resultado = xAdicionarColuna(&tab, &jogo,&jogador1,&jogador2);
                        if(resultado == 1){
                            inicial=guardaJogadas(&tab, inicial);
                            incJogada(&tab);
                            trocarJogador(&jogo);
                        }else{
                            printf("Nao apresenta creditos suficientes para aumentar a linha !!");
                        }
                        printf("\n");
                    }else if(comando==6){
                        guardar(&tab,&jogador1,&jogador2,&jogo, inicial);
                    }
                    else if (comando == 7) {
                        passar=2;
                    }
               } else {
                    trocarJogador(&jogo);
                    int final = fimjogo(&jogador1, &jogador2, &jogo, &tab, inicial);
                    return final;
                }
            }while (passar != 2);
            break;
        case 2:
            do{
                if(verificaLinha(&tab) == 0 && verificaColuna(&tab) == 0 && verificaDiagonal(&tab) == 0){
                    mostrarTab(&tab);
                    apresentarDados(&jogador1, &jogador2, &jogo, &tab);
                    if(jogo.jogadoratual==0){
                        menu2(2);
                    }else{
                        menu2(4);
                    }
                    scanf("%d", &comando);
                    if(jogo.jogadoratual==0){
                    if (comando == 1) {
                        int jogada;
                        do {
                            lerJogada(&tab, &jogo);
                            jogo.linhajogada = jogo.linhajogada - 1;
                            jogo.colunajogada = jogo.colunajogada - 1;
                            jogada = mudarCor(&tab, &jogo);
                        } while (jogada != 1);
                        inicial=guardaJogadas(&tab, inicial);
                        incJogada(&tab);
                        trocarJogador(&jogo);
                    } else if (comando == 2) {
                        int jogada;
                        do {
                            lerJogada(&tab, &jogo);
                            jogo.linhajogada = jogo.linhajogada - 1;
                            jogo.colunajogada = jogo.colunajogada - 1;
                            jogada = jogarPedra(&jogador1, &jogador2, &jogo, &tab);
                        } while (jogada != 1);
                        inicial=guardaJogadas(&tab, inicial);
                        incJogada(&tab);
                        trocarJogador(&jogo);
                        //insereTabuleiro(tabuleiros, &tab);
                    }else if(comando ==3){
                        int certo=0, jogadas;
                        if(tab.jogada>1){
                            printf("=========================\n\n");

                            do{
                                printf("Quantas jogadas pretende mostrar? \n");
                                scanf("%d", &jogadas);
                                if(jogadas<tab.jogada){
                                    certo=1;
                                    printf("Vao ser mostradas %d jogadas !!\n", jogadas);
                                }else{
                                    printf("Numero de jogadas pedidas superior ao numero de jogadas totais!! \n");
                                }
                            }while(certo!=1);
                            mostra_jogadas(inicial, jogadas);
                            printf("=========================\n\n");
                        }
                    }else if(comando==4){
                        int resultado = xAdicionarLinha(&tab, &jogo,&jogador1,&jogador2);
                        if(resultado == 1){
                            inicial=guardaJogadas(&tab, inicial);
                            incJogada(&tab);
                            trocarJogador(&jogo);
                        }else{
                            printf("Nao apresenta creditos suficientes para aumentar a linha !!");
                        }
                        printf("\n");
                    }else if(comando==5){
                        int resultado = xAdicionarColuna(&tab, &jogo,&jogador1,&jogador2);
                        if(resultado == 1){
                            inicial=guardaJogadas(&tab, inicial);
                            incJogada(&tab);
                            trocarJogador(&jogo);
                        }else{
                            printf("Nao apresenta creditos suficientes para aumentar a linha !!");
                        }
                        printf("\n");
                    }else if(comando==6){
                        guardar(&tab,&jogador1,&jogador2,&jogo, inicial);
                    }
                    else if (comando == 7) {
                        passar = 2;
                     }
                    }else{
                        int jogada;
                        if(comando==1){
                            do{
                                jogada=jogarAutomatico(&tab,&jogo);
                            }while(jogada!=1);
                            inicial=guardaJogadas(&tab, inicial);
                            incJogada(&tab);
                            trocarJogador(&jogo);
                        }else if(comando==2){
                            guardar(&tab,&jogador1,&jogador2,&jogo, inicial);
                        }else if(comando==3){
                            passar=2;
                        }
                    }
               }else{
                    trocarJogador(&jogo);
                    fimjogo(&jogador1, &jogador2, &jogo, &tab, inicial);
                    return 1;
                }
            }while (passar != 2);
            break;
        default:
            break;
    }
    return 0;
}
// Devolve o resultado do jogo para o main
int jogo() {
    Jogador jogador1, jogador2;
    Tabuleiro tab;

    pTabuleiro inicial = NULL;

    Jogo jogo;
    int carr;
    int comando=0;
    int escolha = 1, passar = 1, decisao;
    if(verificarFicheiro()==1){
        printf("Pretende carregar o jogo guardado ?\n1 - Sim\n2 - Nao\nOpcao: ");
        scanf("%d", &carr);
        if(carr==1){
            inicial=carregar(&tab, &jogador1, &jogador2, &jogo, inicial);
        }else {
            jogo.jogadoratual=0;
            tab.jogada=1;
            criarTab(&tab);
            do {
                menu2(escolha);
                scanf("%d", &comando);
                if (comando == 1) {
                    printf("Modo jogador x jogador escolhido!\n");
                    jogo.modo=1;
                    passar = 2;
                } else if (comando == 2) {
                    printf("Modo jogador x computador escolhido!\n");
                    jogo.modo=2;
                    passar = 2;
                } else if (comando == 3) {
                    return 1;
                } else {
                    printf("Opcao invalida!\n");
                }
            } while (passar != 2);
            inicializarJogadores(jogo.modo,&jogador1,&jogador2);
        }
    }else{

        jogo.jogadoratual=0;
        tab.jogada=1;
        criarTab(&tab);
        do {
            menu2(escolha);
            scanf("%d", &comando);
            if (comando == 1) {
                printf("Modo jogador x jogador escolhido!\n");
                jogo.modo=1;
                passar = 2;
            } else if (comando == 2) {
                printf("Modo jogador x computador escolhido!\n");
                jogo.modo=2;
                passar = 2;
            } else if (comando == 3) {
                return 1;
            } else {
                printf("Opcao invalida!\n");
            }
        } while (passar != 2);
        inicializarJogadores(jogo.modo,&jogador1,&jogador2);
    }
    decisao = acaojogo(jogador1, jogador2, tab, jogo, inicial);
    libertaTab(tab.linhas,tab.tab);
    printf("Tabuleiro libertado !!\n");
    libertaLinked(inicial);
    printf("Lista ligada libertada !!");
    return decisao;
}
// Liberta Tabuleiro
void libertaTab(int linhas,char** tab){
    for(int i=0; i<linhas; i++)
        free(tab[i]);
    free(tab);

}
// Liberta Lista ligada
void libertaLinked(Tabuleiro *inicial){
    pTabuleiro aux;
    while(inicial != NULL){
        aux = inicial;
        libertaTab(aux->linhas,aux->tab);
        free(aux);
        inicial=inicial->prox;
    }
}