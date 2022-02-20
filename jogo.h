//
// TP Programação - Jogo do Semáforo - Realizado por Nuno Gabriel Tavares Honório a2019126457
//

#ifndef TRABALHOP_JOGO_H
#define TRABALHOP_JOGO_H
// Estrutura joga
typedef struct joga{
    int modo;
    int jogadoratual;
    int linhajogada;
    int colunajogada;
}Jogo;
// Estrutura Tabuleiro
typedef struct tabuleiro Tabuleiro, *pTabuleiro;
struct tabuleiro{
    char **tab;
    int jogada;
    int linhas, colunas;
    pTabuleiro prox;
};
// Estrutura Jogador
typedef struct jogador{
    char nome;
    int pedra;
    int adicionar;
}Jogador;

void menu2(int escolha);
void mostrarTab(Tabuleiro *tab);
int mudarCor(Tabuleiro *tab, Jogo *jogo);
int jogarAutomatico(Tabuleiro *tab, Jogo *jogo);
void criarTab(Tabuleiro *tab);
void inicializarJogadores(int modo, struct jogador *pjogador1, struct jogador *pjogador2);
void trocarJogador(Jogo *jogo);
void lerJogada(Tabuleiro *tab, Jogo *jogo);
void apresentarDados(Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *tab);
int jogarPedra(Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *tab);
int verificaLinha(Tabuleiro *tab);
int verificaColuna(Tabuleiro *tab);
int verificaDiagonal(Tabuleiro *tab);
pTabuleiro guardaJogadas(Tabuleiro *tab, Tabuleiro *inicial);
void writeToFile(Tabuleiro *inicial);
void guardar(Tabuleiro *tab, Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *inicial);
pTabuleiro carregar(Tabuleiro *tab, Jogador *jogador1, Jogador *jogador2, Jogo *jogo, Tabuleiro *inicial);
int fimjogo(Jogador *jogador1, Jogador *jogador2, Jogo *jog, Tabuleiro *tab, Tabuleiro *inicial);
void incJogada(Tabuleiro *tab);
void mostra_jogadas(pTabuleiro p, int jogadas);
void adicionarLinha(Tabuleiro *tab);
void adicionarColuna(Tabuleiro *tab);
int xAdicionarColuna(Tabuleiro *tab, Jogo *jogo, Jogador *jogador1, Jogador *jogador2);
int xAdicionarLinha(Tabuleiro *tab, Jogo *jogo, Jogador *jogador1, Jogador *jogador2);
int acaojogo(Jogador jogador1, Jogador jogador2, Tabuleiro tab, Jogo jogo, pTabuleiro inicial);
int jogo();
void libertaTab(int linhas,char** tab);
void libertaLinked(Tabuleiro *inicial);
#endif //TRABALHOP_JOGO_H
