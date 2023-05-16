#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 4
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)


void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;

    print_sep(BOARD_SIZE);
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column <BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(BOARD_SIZE);
    }
}
//funcion para dibujar la tabla vacia segun parametro board_size
void printEmptyBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    for(int row = 0; row < BOARD_SIZE; row++)
    {
        for(int column = 0; column < BOARD_SIZE; column++){
            board[row][column]= '-';
        }
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    char winner = '-';
    //
    // TODO: COMPLETAR
    //
    //verificar las filas
    for(int row = 0; row < BOARD_SIZE; row++)
    {
        if(winner != 'X' && winner != 'O')
        {
            int column = 1;
            while(column < BOARD_SIZE && board[row][column] == board[row][0])
            {
                column++;
            }
            if(column == BOARD_SIZE)
            {
                winner = board[row][0];
            }
        }
    }    
    //verificar columnas
    for(int column = 0; column < BOARD_SIZE; column++)
    {
        if(winner != 'X' && winner != 'O')
        {
            int row = 1;
            while(row < BOARD_SIZE && board[row][column] == board[0][column])
            {
                row++;
            }
            if(row == BOARD_SIZE)
            {
                winner = board[0][column];
            }
        }
    } 
    //verificar diagonal "\"
    if(board[0][0] != winner)
    {
        int i = 1;
        while(i < BOARD_SIZE && board[i][i] == board[0][0])
        {
            i++;
        }
        if(i == BOARD_SIZE)
        {
            winner = board[0][0];
        }
    }
    //verificar diagonal "/"
    if(board[0][BOARD_SIZE-1] != winner)
    {
        int i = 1;
        while(i < BOARD_SIZE && board[i][BOARD_SIZE-1-i] == board[0][BOARD_SIZE-1])
        {
            i++;
        }
        if(i == BOARD_SIZE)
        {
            winner = board[0][BOARD_SIZE-1];
        }
    }
    return winner;
} 

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    bool free_cell=false;
    //
    // TODO: COMPLETAR
    //
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int column = 0; column < BOARD_SIZE; column++) {
        if(board[row][column] == '-'){
            free_cell = true;
        }
        }
    }        
    return free_cell;
}

int main(void)
{
    char board [BOARD_SIZE][BOARD_SIZE];
    printEmptyBoard (board);

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}