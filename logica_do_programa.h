#ifndef ___LOGICA_DO_PROGRAMA_H___
#define ___LOGICA_DO_PROGRAMA_H___
#include "listas.h"
/**
 @file logica_do_programa.h
 Definições dos dados presentes no estado e das funções que o alteram
*/

/**
\brief Funções relacionadas à lógica do programa
*/


/**
\brief Função para jogar
@param estado Apontador para o Estado atual
@param c Coordenada
@return O inteiro 1
*/
int jogar(ESTADO *estado, COORDENADA c);

/**
\brief Função para verificar se uma jogada é possível
@param e Apontador para o Estado atual
@param c Coordenada
@return O inteiro 1 se a jogada for possível, 0 em caso contrário
*/
int verificaJogada (ESTADO *e, COORDENADA c);

/**
\brief Função que verifica se o jogador 1 venceu
@param e Apontador para o Estado atual
@param c Coordenada
@return O inteiro 1 se venceu, 0 em caso contrário
*/
int verifica_Vitoria_Jog1 (ESTADO *e, COORDENADA c);

/**
\brief Função que verifica se o jogador 2 venceu
@param e Apontador para o Estado atual
@param c Coordenada
@return O inteiro 1 se venceu, 0 em caso contrário
*/
int verifica_Vitoria_Jog2 (ESTADO *e, COORDENADA c);

/**
\brief Função que verifica se um jogador está bloqueado, ou seja, não existe nenhuma possibilidade de efetuar uma jogada válida
@param e Apontador para o estado atual
@param c Coordenada
@return O inteiro 1 caso esteja bloqueado, 0 caso contrário
 */
int verifica_Bloqueio (ESTADO *e, COORDENADA c);

/**
\brief
@param c Coordenada
@return
*/
float distancia_a_1 (COORDENADA *c);

/**
\brief
@param c Coordenada
@return
*/
float distancia_a_2 (COORDENADA *c);

/**
\brief
@param e Apontador para o estado atual
@param L Lista de posições possíveis
@return A posição para a qual se pode mover de modo a ficar mais perto do objetivo
*/
COORDENADA* euristica (ESTADO *e, LISTA L);

/**
\brief Função para armazenar as posições possíveis de jogar
@param e Apontador para o estado atual
@param L Lista para ser alterada com as posições possíveis
@param posicoes Array de posições a avaliar
@return A lista L com todas as posições possíveis
*/
LISTA armazena_posicoes(ESTADO *e,LISTA L, COORDENADA *posicoes);

/**
\brief Função para colocar no ecrã as diversas componentes de uma lista
@param L A lista que deve ser reproduzida
*/
void print_LISTA(LISTA L);

/**
\brief Função para executar o comando jog
@param e O estado atual
@param pos A posição atual
@return A melhor jogada possível de forma a aproximar-se do objetivo
*/
COORDENADA jog (ESTADO  *e, COORDENADA pos);

#endif