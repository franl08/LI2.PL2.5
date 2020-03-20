#include <stdio.h>
#ifndef ___CAMADA_DE_INTERFACE_H___
#define ___CAMADA_DE_INTERFACE_H___

/**
 @file camada_de_interface.h
 Definições dos dados presentes no estado e das funções que o alteram
*/

/**
\brief Funções para alterarem a interface
*/

/**
\brief Função para mostrar o tabuleiro
@param e Apontador para o Estado atual
@param f_pointer Apontador de memória para a criação de um ficheiro
 */
void mostrar_tabuleiro(ESTADO *e, FILE * f_pointer);

/**
\brief
@param e Apontador para o Estado atual
@return 0 se houver algum erro ou terminar o jogo, 1 em caso contrário
*/
int interpretador(ESTADO *e);

/**
\brief
@param e Apontador para o Estado atual
*/
void showPrompt (ESTADO *e); // coloca o prompt no ecra

#endif