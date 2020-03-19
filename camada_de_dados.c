#include <stdio.h>
#include <stdlib.h>
#include "camada_de_dados.h"



void inicializar_tabuleiro(CASA tab[8][8]){ //incializa o tabuleiro
    int linha,coluna;
    for(linha = 7; linha > 0 ; linha--){
        if(linha == 4){
            for(coluna = 0 ; coluna < 8 ; coluna++){
                if(coluna == 4)
                    tab [linha] [coluna] = BRANCA;
                else
                    tab [linha] [coluna] = VAZIO;
            }
        }
        else {
            for(coluna = 8; coluna > 0 ; coluna--)
                tab [linha] [coluna] = VAZIO;
        }
    }
}


int obter_jogador_atual(ESTADO *estado){ // retorna o numero do jogador atual
    return estado->jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *estado){ // retorna o numero de jogadas que esta armazenado no estado
    return estado->num_jogadas;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){ // retorna o estado de uma casa do tabuleiro (VAZIO , BRANCA , PRETA)
    int coluna, linha;
    CASA estadoCasa;
    coluna = c.coluna;
    linha = c.linha;
    estadoCasa = e->tab[linha][coluna];
    return estadoCasa;
}

ESTADO *inicializar_estado(){
    CASA tabuleiro[8][8];                                   // declarar o tabuleiro
    ESTADO *estadoJogo = (ESTADO *) malloc(sizeof(ESTADO)); // declarar o estado
    inicializar_tabuleiro(estadoJogo->tab);                 // modifica a matriz  tabuleiro
    estadoJogo->jogador_atual = 1;                          // inicializa o jogador_atual
    estadoJogo->num_jogadas = 0;                            // inicializa o número de jogadas
    estadoJogo->ultima_jogada.coluna = 4;                   //incializa a coordenada coluna da ultima jogada
    estadoJogo->ultima_jogada.linha = 4;                    //incializa a coordenada linha da ultima jogada
    return estadoJogo;
}

void atualiza_estado_jogo (ESTADO *e, COORDENADA c){
    int coluna, linha, jogadorAtual;

    coluna = c.coluna;
    linha = c.linha;
    jogadorAtual = obter_jogador_atual(e);
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA; // muda a peca anterior para vazio
    e->tab[linha][coluna] = BRANCA; // muda a peça em que o jogador pretende jogar
    e->ultima_jogada = c;           // altera a ultima jogada
    e->num_jogadas++;               // aumenta o numero de jogadas
    if(jogadorAtual == 1 ) {        // armazena a jogada no array JOGADAS
        e->jogadas[e->num_jogadas - 1].jogador1 = c;
        e->jogador_atual = 2;
    }
    else { // armazena a jogada no array JOGADAS
        e->jogadas[e->num_jogadas - 1].jogador2 = c;
        e->jogador_atual = 1 ;
    }
}

void incrementa_num_comandos(ESTADO *e){
    e->num_comandos++;
}

int obter_num_comandos(ESTADO *e){
    return e->num_comandos;
}