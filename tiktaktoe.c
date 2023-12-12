#include <stdio.h>

#define boardsize 9

char board[boardsize];

void printboard();
void createboardarray();
int wincon();
int cpumove();
int gameover();
int boardfull();
void makemove();

int main(void)
{
    createboardarray();
    // player 1 = human, player -1 = cpu
    int player = 1;
    int position;

    printf("Tic Tac Toe\n\n");

    do
    {  
        printboard();

        if (player == 1)
        {
            printf("Choose position (1 - 9): ");
            scanf("%d", &position);
            position--;

            if (position >= 0 && position < boardsize && board[position] == ' ')
            {
                board[position] = 'X';
            }
            else
            {
                printf("Invalid move\n");
                continue;
            }
        }
        else
        {
            makemove();
        }

        if (!gameover())
        {
        player = -player;
        }

    } while (!gameover() && !boardfull());

    printboard();

    if (gameover() && wincon() == 1)
    {
        printf("cpu won!\n");
    }
    else if (gameover() && wincon() == -1)
    {
        printf("you won!\n");
    }
    else
    {
        printf("draw!\n");
    }

    return 0;
}


void createboardarray()
{
    for (int i = 0; i < boardsize; i++)
    {
        board[i] = ' ';
    }
}

void printboard()
{
    for (int i = 0; i < boardsize; i++)
    {
        printf(" %c ", board[i]);

        if (i % 3 == 2 && i < boardsize - 1)
        {
            printf("\n-----------\n");
        }

        if (i % 3 < 2)
        {
            printf("|");
        }
    }
    printf("\n\n");
}

int gameover()
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ')
        {
            return 1;
        }

        if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != ' ')
        {
            return 1;
        }
    }

    if ((board[2] == board[4] && board[4] == board[6] && board[2] != ' ') || (board[0] == board[4] && board[4] == board[8] && board[0] != ' '))
    {
        return 1;
    }

    return 0;
}

int wincon()
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
        {
            if (board[i] == 'X')
            {
                return -1;
            }
            else if (board[i] == 'O')
            {
                return 1;
            }
        }

        if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2])
        {
            if (board[i * 3] == 'X')
            {
                return -1;
            }
            else if (board[i * 3] == 'O')
            {
                return 1;
            }
        }
    }

    if ((board[2] == board[4] && board[4] == board[6]) || (board[0] == board[4] && board[4] == board[8]))
    {
        if (board[4] == 'X')
        {
            return -1;
        }
        else if (board[4] == 'O')
        {
            return 1;
        }
    }

    return 0;
}

int cpumove()
{
    for (int i = 0; i < boardsize; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'O';
            if (wincon() == 1)
            {
                board[i] = ' '; 
                return i;
            }
            board[i] = ' '; 
        }
    }

    for (int i = 0; i < boardsize; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'X';
            if (wincon() == -1)
            {
                board[i] = 'O'; 
                return i;
            }
            board[i] = ' '; 
        }
    }

    for (int i = 0; i < boardsize; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'O';
            return i;
        }
    }

    return -1;
}



void makemove()
{
    int besteval = cpumove();
    
    if (besteval != -1 && board[besteval] == ' ')
    {
        board[besteval] = 'O';
    }
}


int boardfull()
{
    for (int i = 0; i < boardsize; ++i)
    {
        if (board[i] == ' ')
        {
            return 0;
        }
    }
    return 1;
}
