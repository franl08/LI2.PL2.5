#ifndef ___CAMADA_DE_DADOS_H___
#define ___CAMADA_DE_DADOS_H___

/**
@file camada_de_dados.h
Definição do estado e das funções que o manipulam
*/

//Aqui dentro aparece o código correspondente aos protótipos
//CASA
/**
\brief Tipo de dados para a casa
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

//COORDENADA
typedef struct {
	int coluna;
	int linha;
} COORDENADA;

//JOGADA
typedef struct {
	COORDENADA jogador1;
	COORDENADA jogador2;
} JOGADA;

//JOGADAS
typedef JOGADA JOGADAS[32];

//ESTADO
typedef struct {
	CASA tab[8][8];             //armazena informação sobre o tabuleiro
	COORDENADA ultima_jogada;	//a coordenada da última jogada
	JOGADAS jogadas;			//armazena informação sobre as jogadas
	int num_jogadas;			//indica quantas jogadas foram efetuadas
	int jogador_atual;			//indica qual é o jogador a jogar
	int num_comandos;           //aramzena o número total de comandos
} ESTADO;


ESTADO *inicializar_estado();                    //Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
void inicializar_tabuleiro(CASA tab[8][8]);      //Função que inicializa o tabuleiro
int obter_jogador_atual(ESTADO *estado);		 //Esta função permite obter o número do jogador atual
int obter_numero_de_jogadas(ESTADO *estado);	 //Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores)
CASA obter_estado_casa(ESTADO *e, COORDENADA c); //Esta função permite obter o estado atual da casa
void atualiza_estado_jogo (ESTADO *e, COORDENADA c);//Esta função atualiza o estado do jogo apos a jogada
void incrementa_num_comandos(ESTADO *e);            // Funcao que altera o numero de comandos na camada de dados
int obter_num_comandos(ESTADO *e);                  // Retorna o número atual de comandos;
void modifica_num_jogadas (ESTADO *e , int numJogadas); // ultilizada para alterar o valor do numero de jogadas atual para quebrar o loop no main e terminar o programa
COORDENADA obter_ultima_jogada(ESTADO *e );             // retorna a ultima jogada
#endif