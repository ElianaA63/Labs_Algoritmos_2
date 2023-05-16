#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

//me fijo ganador en las filas recorriendo las columnas
char get_winner_row (char board[3][3], unsigned int row)
{
    //inicializo en la primera posicion del tablero
    char winner = board[row][0];

    //recorro las columnas
    for (unsigned int column = 0; column < 3 && winner != '-'; column ++)
    {
        if(winner != board[row][column])
        {
            winner = '-';
        }
    }
    return winner;
}

// me fijo ganador en las columnas recorriendo las filas
char get_winner_column(char board[3][3], unsigned int column)
{
    //inicializo en la primera posicion del tablero  
    char winner = board [0][column];
    //recorro las filas  
    for (unsigned int row = 0; row < 3 && winner != '-'; row ++)
    {
        if(winner != board[row][column])
        {
            winner = '-';
        }
    }
    return winner;

}

//me fijo ganador en la diagonal de izq la final "\" 
char get_winner_diagonal_primera(char board[3][3])
{
    char winner = board[0][0];
    for (unsigned int j = 0; j < 3 && winner != '-'; j++)
    {
        if ( winner != board[j][j])
        {
            winner = '-';
        }
    }
    return winner;
}

//me fijo ganador en la diagonal de derecha al final "/" 
char get_winner_diagonal_segunda(char board[3][3])
{
    char winner = board[2][0];
    for (unsigned int j = 0; j < 3 && winner != '-' ; j++)
    {
        if ( winner != board[2-j][j])
        {
            winner = '-';
        }
    }
    return winner;
}

char get_winner(char board[3][3])
{
    char winner = get_winner_diagonal_primera(board);
    //
    // TODO: COMPLETAR
    //
    if ( winner == '-')
    {
        winner = get_winner_diagonal_segunda(board);
    }
    
    for (unsigned int k = 0; k<3 && winner == '-'; k++)
    {
        winner = get_winner_row(board,k);

        if ( winner == '-')
        {
            winner = get_winner_column( board,k); 
        }
    }
    return winner;
}

bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    //
    // TODO: COMPLETAR
    //
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
        if(board[row][column] == '-'){
            free_cell = true;
        }
        }
    }        
    return free_cell;
}

int main(void)
{
    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

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
            int row = cell / 3;
            int colum = cell % 3;
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
